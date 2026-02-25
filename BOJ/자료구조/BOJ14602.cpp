#include <bits/stdc++.h>
using namespace std;

int arr[31][31];
int ans[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M,N,K,W;
    cin >> M >> N >> K >> W;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < M-W+1; i++) {
        for(int j = 0; j < N-W+1; j++) {
            vector<int> mv;
            for(int k = 0; k < W; k++) {
                for(int l = 0; l < W; l++) {
                    mv.push_back(arr[i+k][j+l]);
                }
            }
            sort(mv.begin(),mv.end());
            ans[i][j] = mv[mv.size()/2];
        }
    }

    for(int i = 0; i < M-W+1; i++) {
        for(int j = 0; j < N-W+1; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    
    return 0;
}
// 알고리즘: 슬라이딩 윈도우, 정렬, 중앙값
