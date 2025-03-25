#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fld[26][26];
int vst[26][26];
vector<int> v;

int N,M;

int hnum = 0;

void dfs(int n, int m) {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vst[n][m] = 1;
    hnum++;
    for(int i = 0; i < 4; i++) {
        int nx = n+dx[i];
        int ny = m+dy[i];
        if(nx < 0 || nx >= N) continue;
        if(ny < 0 || ny >= N) continue;
        if(fld[nx][ny] == 1 && vst[nx][ny] == 0) {
            dfs(nx,ny);
        }
    }

}

int ans() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(fld[i][j] == 1 && vst[i][j] == 0) {
                hnum = 0;
                cnt++;
                dfs(i,j);
                v.push_back(hnum);
            }
        }
    }

    return cnt;
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d",&fld[i][j]);
        }
    }

    int Fans = ans();
    sort(v.begin(),v.end());
    cout << Fans << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
   

}