#include<bits/stdc++.h>
using namespace std;

int arr[101][101][101];
int chk[101][101][101];
int cnt[101][101][101];
struct pos {
    int x;
    int y;
    int z;
};

int main() {
    
    queue<pos> q;
    int movX[6] = {1,-1,0,0,0,0};
    int movY[6] = {0,0,1,-1,0,0};
    int movZ[6] = {0,0,0,0,1,-1};
    int cntmax = 0;
    fill_n(cnt[0][0],101*101*101,1<<20);

    int n,m,h;
    cin >> n >> m >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                cin >> arr[k][j][i];
                if(arr[k][j][i] == 1) { 
                    chk[k][j][i] = 1;
                    pos temp;
                    temp.x = k, temp.y = j, temp.z = i;
                    q.push(temp);
                    cnt[k][j][i] = 0;
                }
            }
        }
    }

    //BFS
    
    

    while(!q.empty()) {
        pos ex = q.front();
        int tempcnt = cnt[ex.x][ex.y][ex.z];
        cntmax = tempcnt < cntmax ? cntmax : tempcnt; 
        chk[ex.x][ex.y][ex.z] = 1;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int nx = ex.x+movX[i];
            int ny = ex.y+movY[i];
            int nz = ex.z+movZ[i];
            if(nx < 0 || nx > n-1) continue;
            if(ny < 0 || ny > m-1) continue;
            if(nz < 0 || nz > h-1) continue;
            if(chk[nx][ny][nz] == 0 && arr[nx][ny][nz] == 0) {
                pos temp = {nx,ny,nz};
                q.push(temp);
                cnt[nx][ny][nz] = cnt[nx][ny][nz] > tempcnt+1 ? tempcnt+1 : cnt[nx][ny][nz]; 
                chk[nx][ny][nz] = 1;
            }
        }
    }

    //FullCheck
    bool flag = true;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[k][j][i] == 0 && chk[k][j][i] == 0) {
                    flag = false;
                    break;
                }
            }
        }
    }

    if(!flag) cout << -1;
    else {
        cout << cntmax;
    }


}
// 알고리즘: BFS (3D), 다중 소스 BFS (토마토)
