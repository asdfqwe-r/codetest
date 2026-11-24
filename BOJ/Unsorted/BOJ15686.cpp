#include <bits/stdc++.h>
using namespace std;

int N,M;

int G[50][50];
vector<pair<int,int>> C;
vector<pair<int,int>> H;
int ans = 0x3fffffff;

int dist(pair<int,int> p1, pair<int,int> p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;

    int a1 = x1 > x2?x1-x2:x2-x1;
    int a2 = y1 > y2?y1-y2:y2-y1;
    return a1+a2;
}

void f(int cnt, int idx, vector<int> &v) {
    if(cnt == M) {
        int comp = 0;
        for(auto px : H) {
            int ex = 0x3fffffff;
            for(auto ix : v) { 
                ex = min<int>(ex, dist(C[ix], px));
            }
            comp += ex;
        }
        ans = min<int>(ans, comp);
    }

    for(int i = idx; i < C.size(); i++) {
        vector<int> v1 = v;
        v1.push_back(i);
        f(cnt+1, i+1, v1);
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> G[i][j];
            if(G[i][j] == 2) {
                C.push_back({i,j});
            }
            if(G[i][j] == 1) {
                H.push_back({i,j});
            }
        }
    }

    vector<int> v;
    f(0,0,v);

    cout << ans;

    
    return 0;
}