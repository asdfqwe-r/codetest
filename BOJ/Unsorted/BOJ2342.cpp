#include <bits/stdc++.h>
using namespace std;

int DP[100001][5][5];
vector<int> v;

int Move(int a, int b) {
    if(a == b) return 1;
    if(a == 0) return 2;
    if(a - b == 2 || a-b == -2) return 4;
    else return 3;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(DP,-1,sizeof(DP));
    
    DP[0][0][0] = 0;
    int idx = 0;
    while(1) {
        int x;
        cin >> x;
        v.push_back(x);
        if(x == 0) break;

        idx++;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(DP[idx-1][i][j] == -1) continue;
                

                if(DP[idx][x][j] == -1) DP[idx][x][j] = DP[idx-1][i][j] + Move(i,x);
                else DP[idx][x][j] = min<int>(DP[idx-1][i][j] + Move(i,x),DP[idx][x][j]);

                if(DP[idx][i][x] == -1) DP[idx][i][x] = DP[idx-1][i][j] + Move(j,x);
                else DP[idx][i][x] = min<int>(DP[idx-1][i][j] + Move(j,x),DP[idx][i][x]);
            }
        }
    }
    
    int ans = 500000;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(DP[idx][i][j] == -1) continue;
            ans = min<int>(ans,DP[idx][i][j]);
        }
    }
    cout << ans;
    return 0;
}

