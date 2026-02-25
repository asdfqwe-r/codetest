#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int arr[101][101];
int arr2[101][101];
int movX[4] = {1,-1,0,0};
int movY[4] = {0,0,1,-1};
int vst1[101][101];
int vst2[101][101];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if(x == 'R') arr[i][j] = 1;
            if(x == 'G') arr[i][j] = 2;
            if(x == 'B') arr[i][j] = 3;

            if(x == 'R') arr2[i][j] = 1;
            if(x == 'G') arr2[i][j] = 1;
            if(x == 'B') arr2[i][j] = 3;
        }
    }

    //Normal
    int cnt1 = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vst1[i][j]) {
                cnt1++;
                int comp = arr[i][j];
                queue<pair<int,int>> q;
                q.push({i,j});

                while(!q.empty()) {
                    int tempx = q.front().first;
                    int tempy = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++) {
                        int exX = tempx + movX[i];
                        int exY = tempy + movY[i];
                        if(exX < 1 || exX > n) continue;
                        if(exY < 1 || exY > n) continue;

                        if(!vst1[exX][exY] && arr[exX][exY] == comp) {
                            q.push({exX,exY});
                            vst1[exX][exY] = 1;
                        }
                    }
                }
                  
            }
        }
    }

    cout << cnt1 << ' ';

    //Colorblind
    int cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vst2[i][j]) {
                cnt2++;
                int comp = arr2[i][j];
                queue<pair<int,int>> q;
                q.push({i,j});

                while(!q.empty()) {
                    int tempx = q.front().first;
                    int tempy = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++) {
                        int exX = tempx + movX[i];
                        int exY = tempy + movY[i];
                        if(exX < 1 || exX > n) continue;
                        if(exY < 1 || exY > n) continue;

                        if(!vst2[exX][exY] && arr2[exX][exY] == comp) {
                            q.push({exX,exY});
                            vst2[exX][exY] = 1;
                        }
                    }
                }
                  
            }
        }
    }

    cout << cnt2;
}
// 알고리즘: BFS, 연결 성분, 색맹 시뮬레이션
