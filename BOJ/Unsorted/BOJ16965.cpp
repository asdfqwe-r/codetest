#include <bits/stdc++.h>
using namespace std;
    
int N;
vector<pair<int,int>> v;

bool MovChk(pair<int,int> p1, pair<int,int> p2) {
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;

    if(x1 < y2 && x2 < x1) return 1;
    if(y1 < y2 && x2 < y1) return 1;
    return 0;
}

bool bfs(pair<int,int> px, int ex, pair<int,int> en) {
    int vst[101] = {0,};
    vst[ex] = 1;
    queue<pair<int,int>> q;
    q.push(px);
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        for(int i = 0; i < v.size(); i++) {
            if(MovChk(idx, v[i]) && !vst[i]) {
                if(v[i] == en) return true;
                q.push(v[i]);
                vst[i] = 1;
            }
        } 
    }
    return false;
}
//BFS
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        if(x == 2) {
            int a,b;
            cin >> a >> b;
            cout << bfs(v[a-1],a-1,v[b-1]) << '\n';
        }
    }
    
    return 0;
}