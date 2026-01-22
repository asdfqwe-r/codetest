#include<bits/stdc++.h>
using namespace std;

// 초기화 값을 -1로 하여 방문 여부를 명확히 함
const int MIN_VAL = -1; 
int N, A, L;
int DP[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> L;
    vector<int> dA(N);
    vector<int> dL(N);
    for(int i = 0; i < N; i++) {
        cin >> dA[i] >> dL[i];
    }

    // DP 초기화
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= L; j++) {
            DP[i][j] = MIN_VAL;
        }
    }

    DP[0][L] = A; // 시작점

    // 1. Forward DP
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= L; j++) {
            if(DP[i][j] == MIN_VAL) continue;

            int curA = DP[i][j];

            // --- Aura Damage 시도 ---
            // 1) X/- 공격 (무조건 오라, 0 미만 시 0)
            if(dL[i] == -1) {
                int nextA = max(0, curA - dA[i]);
                DP[i+1][j] = max(DP[i+1][j], nextA);
            }
            // 2) X/Y 공격 (오라 충분할 때만 선택 가능)
            else if(dA[i] != -1) {
                if(curA >= dA[i]) {
                    DP[i+1][j] = max(DP[i+1][j], curA - dA[i]);
                }
            }

            // --- Life Damage 시도 ---
            // 1) -/Y 공격 또는 2) X/Y 공격 (라이프 선택)
            if(dA[i] == -1 || dL[i] != -1) {
                if(j - dL[i] > 0) { // 라이프는 0 초과여야 생존
                    DP[i+1][j - dL[i]] = max(DP[i+1][j - dL[i]], curA);
                }
            }
        }
    }

    // 2. 도착점 확인
    int CurrL = -1, CurrA = -1;
    for(int i = 1; i <= L; i++) {
        if(DP[N][i] != MIN_VAL) {
            CurrL = i;
            CurrA = DP[N][i];
            break;
        }
    }

    if(CurrL == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << "\n";
    string AnsStr = "";

    // 3. Backward Tracking (역추적)
    for(int i = N - 1; i >= 0; i--) {
        bool recovered = false;

        // [옵션 A: 오라 데미지로 왔는지 확인]
        int PrevL = CurrL; // 오라 데미지는 라이프 변화 없음
        int PrevA = DP[i][PrevL];

        // 이전 상태가 유효해야 함
        if(PrevA != MIN_VAL) {
            // Case 1: X/- (오라 강제, 0 미만은 0으로 처리됨)
            if(dL[i] == -1) {
                // 이전 오라에서 데미지를 입혀서 현재 오라(CurrA)가 되었는지 확인
                // max(0, PrevA - dA[i]) == CurrA 인지 확인
                if(max(0, PrevA - dA[i]) == CurrA) {
                    AnsStr += "A";
                    CurrA = PrevA;
                    recovered = true;
                }
            }
            // Case 2: X/Y (오라 충분)
            else if(dA[i] != -1) {
                // 오라가 충분했고, 단순히 뺀 값이 현재 값인지 확인
                if(PrevA >= dA[i] && (PrevA - dA[i] == CurrA)) {
                    AnsStr += "A";
                    CurrA = PrevA;
                    recovered = true;
                }
            }
        }

        if(recovered) continue; // 찾았으면 다음 단계로

        // [옵션 L: 라이프 데미지로 왔는지 확인]
        // Case: -/Y 이거나 X/Y
        if(dA[i] == -1 || dL[i] != -1) {
            PrevL = CurrL + dL[i]; // 이전 라이프 계산
            
            // ★ 중요: 범위 체크 먼저 수행 (PrevL이 L보다 크면 배열 참조 금지)
            if(PrevL <= L) {
                PrevA = DP[i][PrevL];
                
                // 이전 상태 유효성 체크 & 라이프 데미지는 오라가 변하지 않으므로 같은지 체크
                if(PrevA != MIN_VAL && PrevA == CurrA) {
                    AnsStr += "L";
                    CurrL = PrevL;
                    CurrA = PrevA;
                    recovered = true;
                }
            }
        }
    }

    reverse(AnsStr.begin(), AnsStr.end());
    cout << AnsStr;

    return 0;
}