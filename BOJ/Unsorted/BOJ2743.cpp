#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    v.resize(N);

    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());

    long long sumcomp = 4000000000;
    tuple<int,int,int> ans = {0,0,0};

    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            ll tar = -(v[i]+v[j]);
            
            ll PosIdx = lower_bound(v.begin()+j+1,v.end(),tar) - v.begin();
            if(lower_bound(v.begin()+j+1,v.end(),tar) == v.end()) {
                PosIdx--;
            }
            else if(PosIdx == j+1) {

            }
            else if(abs(-tar + v[PosIdx-1]) < abs(-tar+v[PosIdx])) {
                PosIdx--;
            }
            if(sumcomp > abs(-tar+v[PosIdx])) {
                sumcomp = abs(-tar+v[PosIdx]);
                ans = {v[i],v[j],v[PosIdx]};
            }
            
        }
    }

    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);

    
    return 0;
}