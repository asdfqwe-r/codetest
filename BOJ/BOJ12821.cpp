#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k,n;
    vector<ll> v;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int p;
        ll idx = 0;
        cin >> p;
        for(int j = 0; j < p; j++) {
            ll int x,y;
            cin >> x >> y;

            idx = x*x+y*y<idx?idx:x*x+y*y;
        }
        v.push_back(idx);
    }

    sort(v.begin(), v.end());

    cout << v[k-1] << ".00";
    
    return 0;
}