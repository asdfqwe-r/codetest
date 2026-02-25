#include <bits/stdc++.h>
using namespace std;

int G[501][501];
int vst[501][501];
int dX[4] = {-1,1,0,0};
int dY[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    int cnt(0), MaxArea(-1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            queue<pair<int,int>> q;
            int Area = 1;
            if(vst[i][j] == 0 && G[i][j]) {
                q.push({i,j});
                vst[i][j] = 1;
                cnt++;
            }
            while(!q.empty()) {
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = curx + dX[k];
                    int ny = cury + dY[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!vst[nx][ny] && G[nx][ny]) {
                        vst[nx][ny] = 1;
                        q.push({nx,ny});
                        Area++;
                    }
                }
            }
            MaxArea = MaxArea>Area?MaxArea:Area;

        }
    }

    if(cnt == 0) { 
    cout << 0 << '\n' << 0;
    return 0;
    }
    cout << cnt << '\n' << MaxArea; 
    
    return 0;
}
// 알고리즘: BFS, 연결 성분 크기 (그림)
