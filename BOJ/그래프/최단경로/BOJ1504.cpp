#include <bits/stdc++.h>
using namespace std;

int D[801];
vector<pair<int,int>> G[801];

void Dijkstra(int s, int t) {
    memset(D, 0x3f, sizeof D);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.emplace(D[s] = 0, s);

    while(!pq.empty()) {
        auto [c,v] = pq.top();
        pq.pop();
        if(c == D[v]) {
            for(auto [i,w] : G[v]) {
                if(D[i] > c+w) pq.emplace(D[i] = c+w, i);
            }
        }
    }
    if(D[t] == 0x3f3f3f3f) D[t] = -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,E;
    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    int v1,v2;
    cin >> v1 >> v2;

    int arr1[4] = {1,v1,v2,N};
    int arr2[4] = {1,v2,v1,N};

    int ans, idx(0), flag(0);
    for(int i = 0; i < 3; i++) {
        Dijkstra(arr1[i],arr1[i+1]);
        if(D[arr1[i+1]] == -1) {
            flag++;
            idx = 0x3f3f3f3f;
            break;
        }
        idx += D[arr1[i+1]];
    }
    ans = idx;

    idx = 0;
    for(int i = 0; i < 3; i++) {
        Dijkstra(arr2[i],arr2[i+1]);
        if(D[arr2[i+1]] == -1) {
            flag++;
            idx = 0x3f3f3f3f;
            break;
        }
        idx += D[arr2[i+1]];
    }
    ans = min<int>(idx,ans);
    
    if(flag == 2) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
// 알고리즘: 다익스트라 (Dijkstra), 특정 정점 경유 최단경로
