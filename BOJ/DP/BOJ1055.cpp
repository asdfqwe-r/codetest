#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1001;
int N,K;
int DP[N_MAX];
vector<int> G[N_MAX];
vector<int> v;

int solve(int x) {
    if(DP[x] != -1) return DP[x];

    DP[x] = 0;
    for(int &ex : G[x]) {
        DP[x] = max<int>(DP[x],solve(ex));
    }

    return DP[x] = DP[x] + v[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int T,w;
    cin >> T;

    fill(DP,DP+N_MAX,-1);
    while(T--) {
        cin >> N >> K;
        v.resize(N+1);
        for(int i = 1; i <= N; i++) cin >> v[i];

        for(int i = 0; i < K; i++) {
            int a,b;
            cin >> a >> b;
            G[b].push_back(a);
        }

        cin >> w;
        cout << solve(w) << '\n';

        fill(DP, DP+N_MAX, -1);
        for(int i = 1; i <= N; i++) {
            G[i].clear();
        }
    }
    


    
    return 0;
}
// 알고리즘: DP, 메모이제이션, DAG 위에서 DFS+DP
