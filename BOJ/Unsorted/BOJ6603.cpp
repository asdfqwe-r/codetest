#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> ans(6);

void solve(int cnt, int lstidx) {
    if(cnt == 6) {
        for(auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = lstidx+1; i < v.size(); i++) {
        ans[cnt] = v[i];
        solve(cnt+1, i);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    int k;
    while(cin >> k) {
        v.resize(k);
        for(auto &x : v) cin >> x;

        solve(0,-1);
        cout << '\n';
    }
    
    return 0;
}