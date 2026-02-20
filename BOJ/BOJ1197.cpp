#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> Edge;
vector<int> P(10001,-1);

int find(int x) {
    if(P[x] < 0) return x;
    return P[x] = find(P[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    P[a] = b;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int V,E;
    cin >> V >> E;

    for(int i = 0; i < E; i++) {
        int w,a,b;
        cin >> a >> b >> w;
        Edge.push_back({w,a,b});
    }

    sort(Edge.begin(), Edge.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < E; i++) {
        int w,a,b;
        tie(w,a,b) = Edge[i];
        if(find(a) == find(b) && find(a) != -1) continue;
        ans += w;
        uni(a,b);
        cnt++;
        if(cnt == V-1) break;
    }

    cout << ans;


    
    return 0;
}