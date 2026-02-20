import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
import json
import numpy as np
import os

# ==========================================
# 1. 하이퍼파라미터 및 설정
# ==========================================
BATCH_SIZE = 64
EPOCHS = 50
LEARNING_RATE = 0.001
# 액션 스페이스: 5x5 착수(25) + 5x5에서 5x5로 이동(625) = 650
ACTION_SIZE = 25 + (25 * 25) 
GAMMA = 0.98 # 시간 할인율 (백의 트롤링 방지용)

# macOS Apple Silicon (M1/M2/M3) 지원 확인
if torch.backends.mps.is_available():
    device = torch.device("mps")
    print("🚀 MPS (Apple Silicon GPU) 가속을 사용합니다.")
elif torch.cuda.is_available():
    device = torch.device("cuda")
    print("🚀 CUDA GPU 가속을 사용합니다.")
else:
    device = torch.device("cpu")
    print("⚠️ CPU를 사용합니다. 학습이 느릴 수 있습니다.")

# ==========================================
# 2. 딥러닝 모델 (Actor-Critic 기반 CNN)
# ==========================================
class BlockOmokNet(nn.Module):
    def __init__(self):
        super(BlockOmokNet, self).__init__()
        # 입력 형태: (Batch, 4 Channels, 5, 5)
        self.conv_blocks = nn.Sequential(
            nn.Conv2d(4, 64, kernel_size=3, padding=1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.Conv2d(64, 128, kernel_size=3, padding=1),
            nn.BatchNorm2d(128),
            nn.ReLU(),
            nn.Conv2d(128, 128, kernel_size=3, padding=1),
            nn.BatchNorm2d(128),
            nn.ReLU()
        )
        
        # Policy Head (어떤 수를 둘 것인가?)
        self.policy_head = nn.Sequential(
            nn.Conv2d(128, 2, kernel_size=1),
            nn.BatchNorm2d(2),
            nn.ReLU(),
            nn.Flatten(),
            nn.Linear(2 * 5 * 5, ACTION_SIZE)
            # CrossEntropyLoss를 사용할 것이므로 Softmax는 생략
        )
        
        # Value Head (이 판의 승률은 어떻게 되는가?)
        self.value_head = nn.Sequential(
            nn.Conv2d(128, 1, kernel_size=1),
            nn.BatchNorm2d(1),
            nn.ReLU(),
            nn.Flatten(),
            nn.Linear(1 * 5 * 5, 64),
            nn.ReLU(),
            nn.Linear(64, 1),
            nn.Tanh() # -1(패배) ~ 1(승리) 사이의 값 출력
        )

    def forward(self, x):
        x = self.conv_blocks(x)
        policy = self.policy_head(x)
        value = self.value_head(x)
        return policy, value

# ==========================================
# 3. 데이터셋 클래스 (보상 재설계 포함)
# ==========================================
class OmokDataset(Dataset):
    def __init__(self, jsonl_path):
        self.states = []
        self.pis = []
        self.values = []
        
        print("데이터를 로딩하고 전처리합니다...")
        if not os.path.exists(jsonl_path):
            print(f"⚠️ {jsonl_path} 파일이 없습니다. 더미 데이터를 생성합니다.")
            self._generate_dummy_data()
            return

        with open(jsonl_path, 'r', encoding='utf-8') as f:
            for line in f:
                game = json.loads(line)
                winner = game['winner']
                total_turns = game['total_turns']
                
                for move in game['moves']:
                    player = move['player']
                    state = np.array(move['state'], dtype=np.float32)
                    action = move['action']
                    
                    # Policy 타겟 (원핫 인코딩 또는 MCTS 확률)
                    pi = np.zeros(ACTION_SIZE, dtype=np.float32)
                    if 'pi' in move:
                        pi = np.array(move['pi'], dtype=np.float32)
                    else:
                        pi[action] = 1.0
                    
                    # 💡 핵심: 시간 할인(Time Discount) 적용
                    # 현재 플레이어 기준으로 게임 결과가 승리(1)인지 패배(-1)인지 계산
                    actual_reward = 1.0 if player == winner else -1.0
                    if winner == 0: actual_reward = 0.0 # 무승부
                    
                    # 거리가 멀수록(오래 버틸수록) 패널티가 0에 가까워짐
                    turns_left = total_turns - move['turn']
                    discounted_reward = actual_reward * (GAMMA ** turns_left)
                    
                    # 만약 백(-1)이고 질 게임(-1.0)이라면, 
                    # discounted_reward는 거리가 멀수록 -0.5, -0.3 등으로 약해집니다.
                    # 이를 통해 "오래 버티는 것"을 덜 나쁘다고 학습합니다.
                    
                    self.states.append(state)
                    self.pis.append(pi)
                    self.values.append([discounted_reward])
                    
        print(f"총 {len(self.states)}개의 상태 데이터를 로드했습니다.")

    def __len__(self):
        return len(self.states)

    def __getitem__(self, idx):
        return (torch.tensor(self.states[idx]), 
                torch.tensor(self.pis[idx]), 
                torch.tensor(self.values[idx], dtype=torch.float32))

    def _generate_dummy_data(self):
        # 테스트용 더미 데이터 1000개
        for _ in range(1000):
            self.states.append(np.random.rand(4, 5, 5).astype(np.float32))
            pi = np.zeros(ACTION_SIZE, dtype=np.float32)
            pi[np.random.randint(0, ACTION_SIZE)] = 1.0
            self.pis.append(pi)
            self.values.append([np.random.choice([-1.0, 1.0])])

# ==========================================
# 4. 학습 루프
# ==========================================
def train():
    # 데이터 로더 설정 (game_logs.jsonl 파일이 같은 폴더에 있어야 함)
    dataset = OmokDataset('game_logs.jsonl')
    dataloader = DataLoader(dataset, batch_size=BATCH_SIZE, shuffle=True)
    
    model = BlockOmokNet().to(device)
    optimizer = optim.Adam(model.parameters(), lr=LEARNING_RATE, weight_decay=1e-4)
    
    # 손실 함수
    # Policy: 행동 확률 분포의 차이를 줄임 (Cross Entropy)
    # Value: 승률 예측값의 오차를 줄임 (Mean Squared Error)
    mse_loss = nn.MSELoss()
    
    def ce_loss(pred, target):
        # 타겟이 소프트 라벨(확률)일 수 있으므로 수동으로 구현
        log_softmax = nn.LogSoftmax(dim=1)
        return torch.mean(torch.sum(-target * log_softmax(pred), dim=1))

    print("🚀 학습을 시작합니다...")
    
    for epoch in range(1, EPOCHS + 1):
        model.train()
        epoch_policy_loss = 0.0
        epoch_value_loss = 0.0
        
        for batch_idx, (states, pis, values) in enumerate(dataloader):
            states, pis, values = states.to(device), pis.to(device), values.to(device)
            
            optimizer.zero_grad()
            
            # 순전파
            policy_pred, value_pred = model(states)
            
            # 손실 계산
            p_loss = ce_loss(policy_pred, pis)
            v_loss = mse_loss(value_pred, values)
            total_loss = p_loss + v_loss
            
            # 역전파
            total_loss.backward()
            optimizer.step()
            
            epoch_policy_loss += p_loss.item()
            epoch_value_loss += v_loss.item()
            
        avg_p_loss = epoch_policy_loss / len(dataloader)
        avg_v_loss = epoch_value_loss / len(dataloader)
        
        print(f"에포크 [{epoch}/{EPOCHS}] | "
              f"Policy Loss: {avg_p_loss:.4f} | "
              f"Value Loss: {avg_v_loss:.4f}")
        
        # 모델 저장 (10 에포크마다)
        if epoch % 10 == 0:
            torch.save(model.state_dict(), f"block_omok_model_ep{epoch}.pth")
            print(f"💾 모델 저장됨: block_omok_model_ep{epoch}.pth")

if __name__ == '__main__':
    train()