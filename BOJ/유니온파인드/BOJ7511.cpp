#include <bits/stdc++.h>
using namespace std;

vector<int> P(1e6+1,-1);

int find(int x) {
    if(P[x] < 0)
        return x;
    return P[x] = find(P[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    P[v] = u;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    int n,k;

    for(int i = 0; i < t; i++) {
        fill(P.begin(), P.begin()+n, -1);
        
        cin >> n >> k;
        for(int j = 0; j < k; j++) {
            int a,b;
            cin >> a >> b;
            uni(a,b);
        }
        int m;
        cin >> m;

        cout << "Scenario " << i+1 << ":" << '\n';

        for(int j = 0; j < m; j++) {
            int a,b;
            cin >> a >> b;
            if(find(a) == find(b)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        cout << '\n';
    }
    
    return 0;
}
// 알고리즘: 유니온 파인드 (Union-Find)
