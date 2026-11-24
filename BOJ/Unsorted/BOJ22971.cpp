#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
vector<int> v;
vector<int> DP(5001, 1);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] >= v[i]) continue;
            DP[i] = (DP[i]+DP[j])%MOD;
        }
        cout << DP[i] << ' ';
    }

    
}