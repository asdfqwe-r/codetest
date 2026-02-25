#include <bits/stdc++.h>
using namespace std;

int D[1001], P[1001];
vector<pair<int,int>> G[1001];

void Dijkstra(int s, int t) {
    memset(D, 0x3f, sizeof(D));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //Add, node
    pq.emplace(D[s]=0,s);
    while(!pq.empty()) {
        auto [c,v] = pq.top();
        pq.pop();
        if(c == D[v]) {
            for(auto [i,w] : G[v]) {
                if(D[i] > c + w) {
                    pq.emplace(D[i]=c+w,i);
                    P[i] = v;
                }
            }
        }
    }

    vector<int> path;
    for(int i = t; i != s; i = P[i]) path.push_back(i);
    path.push_back(s);
    reverse(path.begin(), path.end());

    cout << D[t] << '\n';
    cout << path.size() << '\n';
    for(auto x : path) cout << x << ' ';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
    }
    int st, end;
    cin >> st >> end;
    Dijkstra(st,end);
    return 0;
}
// 알고리즘: 다익스트라 (Dijkstra), 경로 추적, 우선순위 큐
