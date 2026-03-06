#include <bits/stdc++.h>
using namespace std;

long long LL_INF = 0x3FFFFFFFFFFFFFFF;

long long DP[501][501];
vector<long long> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long ans = LL_INF;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        long long a,b;
        cin >> a >> b;
        if(i == 0) {
            v.push_back(a);
            v.push_back(b);
        }
        else v.push_back(b);
    }

    for(int diff = 2; diff <= N; diff++) {
        for(int i = 0; i <= N-diff; i++) {
            DP[i][i+diff] = LL_INF;
            for(int k = i+1; k < i+diff; k++) {
                DP[i][i+diff] = min(DP[i][i+diff], DP[i][k] + DP[k][i+diff] +v[i]*v[k]*v[i+diff]);
            }
        }
    }

    cout << DP[0][N];

    return 0;
}