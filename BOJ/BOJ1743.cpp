#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int arr[101][101];
int vst[101][101];
int n,m;
int maxA = 0;
int cnt = 1;

void dfs(int x, int y) {
    int movX[4] = {1,-1,0,0};
    int movY[4] = {0,0,-1,1};
    
    vst[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x+movX[i];
        int ny = y+movY[i];
        if(nx <= 0 || nx > n) continue;
        if(ny <= 0 || ny > m) continue;

        if(arr[nx][ny] == 1 && vst[nx][ny] == 0) {
            cnt++;
            dfs(nx,ny);
        }
    }
}


int main() {
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cnt = 1;
            if(arr[i][j] == 1 && vst[i][j] == 0) {
            dfs(i,j);
            }
            maxA = maxA>cnt?maxA:cnt;
        }
    }

    cout << maxA;


}