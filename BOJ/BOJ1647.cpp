#include <bits/stdc++.h>
using namespace std;

int P[100001];

int Find(int x) {
    return P[x] < 0 ? x : P[x] = Find(P[x]);
}

bool Uni(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    P[u] = v; return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin >> N >> M;

    vector<tuple<int,int,int>> v; //weight, from, to
    for(int i = 1, a,b,w; i<=M; i++) {
        cin >> a >> b >> w;
        v.push_back({w,a,b});
    }
    long long int ans(0), cnt(0);
    sort(v.begin(), v.end());
    for(int i = 1; i <= N; i++) P[i] = -1;
    for(auto [w,a,b] : v) {
        if(cnt == N-2) break;
        if(Uni(a,b)) {
            ans += w;
            cnt++;
        }
    }

    cout << ans;

    
    return 0;
}