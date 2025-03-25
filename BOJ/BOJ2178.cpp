#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;
int vst[101][101] = {0,};
int arr[101][101];
int bfs(int n, int m) {
    q.push(make_pair(0,0));

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
        
    while(1) {
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout << x << y << endl;
        if(x == n && y == m) return arr[x][y];
        vst[x][y] = 1;
        
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n) continue;
            if(ny < 0 || ny > m) continue;
            if(arr[nx][ny] == 1 && vst[nx][ny] == 0) {
                q.push(make_pair(nx,ny));
                arr[nx][ny] = arr[x][y] + 1;
            }

        }

    }
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        scanf("%1d",&arr[i][j]);
    }

    printf("%d",bfs(n-1,m-1));
    cout << sizeof(q.front().first);
}
