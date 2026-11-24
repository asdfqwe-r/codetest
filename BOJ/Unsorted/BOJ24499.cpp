#include <bits/stdc++.h>
using namespace std;

int s[100001];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    int all = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        all += x;
    }

    for(int i = 0; i < N; i++) {
        s[i+1] = s[i] + v[i];
    }
    
    int ans = -1;

    for(int i = 0; i+K <= N; i++) {
        ans = max<int>(ans,s[i+K] - s[i]);
    }
    for(int i = 0; i+N-K <= N; i++) {
        int idx = s[i+N-K] - s[i];
        ans = max<int>(ans,all-idx);
    }

    cout << ans;
    
    return 0;
}