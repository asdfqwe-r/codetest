#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> gap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //Greedy
    int N,K;
    cin >> N >> K;

    v.resize(N);
    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());
    gap.push_back(v[0]);

    for(int i = 1; i < N; i++) {
        gap.push_back(v[i]-v[i-1]);
    }

    sort(gap.begin(), gap.end());

    int ans = 0;
    for(int i = 0; i < N-K; i++) {
        ans += gap[i];
    }
    cout << ans;
    
    return 0;
}