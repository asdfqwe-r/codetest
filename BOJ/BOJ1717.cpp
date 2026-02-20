#include <bits/stdc++.h>
using namespace std;

vector<int> P(1e6+1,-1);

int find(int x) {
    while(P[x] >= 0) {
        x = P[x];
    }
    return x;
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) P[v] = u;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x,a,b;
        cin >> x >> a >> b;
        if(x == 0) {
            uni(a,b);
        }
        if(x == 1) {
            if(find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}