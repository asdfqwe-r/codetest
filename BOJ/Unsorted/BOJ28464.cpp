#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    v.resize(N);

    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());
    
    int ans1(0), ans2(0);
    for(int i = 0; i < N; i++) {
        if(i <= N/2-1) ans1 += v[i];
        else ans2 += v[i];
    }

    cout << ans1 << ' ' << ans2;
    return 0;
}