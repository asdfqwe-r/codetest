#include <bits/stdc++.h>
using namespace std;

vector<int> G[10001];
int P[10001];
vector<int> Ch[10001];
int memo[10001];

void dfs(int cur, int parent) {
    for(auto x : G[cur]) {
        if(x == parent) {
            P[cur] = parent;
            continue;
        }
        Ch[cur].push_back(x);
        dfs(x, cur);
    }
} 

int NodeCnt(int cur) {
    int ret = 0;
    if(Ch[cur].size() == 0) return 1;
    for(auto x : Ch[cur]) {
        if(memo[x] != -1) {
            ret += memo[x];
        }
        else {
            ret += NodeCnt(x);
        }
    }
    ret++;
    memo[cur] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("input.txt", "r", stdin);
    
    int N,R,Q;
    cin >> N >> R >> Q;

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    memset(memo, -1, 10001*sizeof(int));

    dfs(R, -1);

    for(int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << NodeCnt(x) << '\n';
    }


    


    return 0;
}
// 알고리즘: 트리 DP, DFS, 서브트리 크기
