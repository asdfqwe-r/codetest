#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n,m;
int movX[4] = {-1,1,0,0};
int movY[4] = {0,0,-1,1};
int arr[501][501];
int ans;
int vst[501][501];

void dfs(int x, int y, int len, int sum) {
    if(len == 4) {
        ans = ans > sum ? ans : sum;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + movX[i];
        int ny = y + movY[i];

        if(nx < 0 || nx >= n) continue;
        if(ny < 0 || ny >= m) continue;

        if(!vst[nx][ny]) {
            vst[nx][ny] = 1;

            dfs(nx,ny,len+1,sum+arr[nx][ny]);

            vst[nx][ny] = 0;
        }
    }

    if(x-1 >= 0 && x+1 < n && y-1 >= 0) {
        int temp = arr[x][y] + arr[x-1][y] + arr[x+1][y] + arr[x][y-1];
        ans = ans > temp ? ans : temp;
    }
    
    if(x-1 >= 0 && x+1 < n && y+1 < m) {
        int temp = arr[x][y] + arr[x-1][y] + arr[x+1][y] + arr[x][y+1];
        ans = ans > temp ? ans : temp;
    }

    
    if(x-1 >= 0 && y-1 >= 0 && y+1 < m) {
        int temp = arr[x][y] + arr[x-1][y] + arr[x][y-1] + arr[x][y+1];
        ans = ans > temp ? ans : temp;
    }

    
    if(x+1 < n && y-1 >= 0 && y+1 < m) {
        int temp = arr[x][y] + arr[x+1][y] + arr[x][y-1] + arr[x][y+1];
        ans = ans > temp ? ans : temp;
    }
    
    
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vst[i][j] = 1;
            
            dfs(i,j,1,arr[i][j]);

            vst[i][j] = 0;
        }
    }

    

    cout << ans;

    
}
// 알고리즘: DFS, 브루트포스, 테트로미노
