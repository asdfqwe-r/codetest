#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 32001;
int N,M;
int indeg[N_MAX];
vector<int> G[N_MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    queue<int> q;

    for(int i = 1; i <= M; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        indeg[y]++;
    }

    for(int i = 1; i <= N; i++) {
        if(!indeg[i]) q.push(i);
    }

    while(!q.empty()) {
        int ex = q.front();
        q.pop();
        cout << ex << ' ';
        for(auto &x : G[ex]) {
            indeg[x]--;
            if(indeg[x] == 0) q.push(x);
        }   
    }


    return 0;
}
// 알고리즘: 위상 정렬 (Topological Sort), BFS (Kahn's algorithm)
