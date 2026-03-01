#include <bits/stdc++.h>
using namespace std;

int temp[1001][3];
int DP[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<vector<int>> G(N,vector<int>(3,0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            G[i][j] = x;
            temp[i][j] = x;
        }
    }
    int ans = 2000000;

    //0 고정
    temp[0][0] = G[0][0];
    temp[0][1] = 1001;
    temp[0][2] = 1001;
    memset(DP,0x3f,sizeof(DP));
    DP[0][0] = temp[0][0];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(k == j) continue;
                DP[i][j] = min<int>(DP[i][j], DP[i-1][k]+temp[i][j]);
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        if(i == 0) continue;
        ans = min<int>(ans,DP[N-1][i]);
    }

    //1 고정
    temp[0][0] = 1001;
    temp[0][1] = G[0][1];
    temp[0][2] = 1001;
    memset(DP,0x3f,sizeof(DP));
    DP[0][1] = temp[0][1];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(k == j) continue;
                DP[i][j] = min<int>(DP[i][j], DP[i-1][k]+temp[i][j]);
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        if(i == 1) continue;
        ans = min<int>(ans,DP[N-1][i]);
    }

    //2 고정
    temp[0][0] = 1001;
    temp[0][1] = 1001;
    temp[0][2] = G[0][2];
    memset(DP,0x3f,sizeof(DP));
    DP[0][2] = temp[0][2];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(k == j) continue;
                DP[i][j] = min<int>(DP[i][j], DP[i-1][k]+temp[i][j]);
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        if(i == 2) continue;
        ans = min<int>(ans,DP[N-1][i]);
    }

    cout << ans;


    return 0;
}