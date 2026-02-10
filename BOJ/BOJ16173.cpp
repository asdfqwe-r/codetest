#include <bits/stdc++.h>
using namespace std;

int G[4][4];
int vst[300][300];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    vst[0][0] = 1;
    int flag = 0;

    while(!q.empty()) {
        int NowX = q.front().first;
        int NowY = q.front().second;
        q.pop();

        int NextX = NowX + G[NowX][NowY];
        int NextY = NowY + G[NowX][NowY];

        if(NowX == n-1 && NowY == n-1) {
            flag = 1;
            break;
        }



        if(NowX + G[NowX][NowY] >= 0 && NowX + G[NowX][NowY] < n && !vst[NextX][NowY]) {
            q.push({NowX + G[NowX][NowY], NowY});
            vst[NextX][NowY] = 1;
        }
        if(NowY + G[NowX][NowY] >= 0 && NowY + G[NowX][NowY] < n && !vst[NowX][NextY] ) {
            q.push({NowX, NowY + G[NowX][NowY]});
            vst[NowX][NextY] = 1;
        }
    }

    if(flag) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}