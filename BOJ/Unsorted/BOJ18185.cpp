#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll ans = 0;

int main() {
    fastio;
    
    int N;
    cin >> N;
    vector<int> v(N);
    for(auto &x : v) cin >> x;

    for(int i = 0; i < N-2; i++) {
        if(v[i+1] <= v[i+2]) {
            int ax = min(v[i], v[i+1]);
            ans += 7*ax;
            for(int j = i; j <= i+2; j++) {
                v[j] -= ax;
            }
            if(v[i] != 0) {
                ans += 3*v[i];
                v[i] = 0;
            }
        }
        else {
            int ax = min(v[i], v[i+1]-v[i+2]);
            ans += 5*ax;
            v[i] -= ax;
            v[i+1] -= ax;

            int bx = min(v[i], v[i+1]);
            ans += 7*bx;
            v[i] -= bx;
            v[i+1] -= bx;
            v[i+2] -= bx;

            if(v[i] != 0) {
                ans += 3*v[i];
                v[i] = 0;
            }
        }
    }

    int ax = min(v[N-2], v[N-1]);
    ans += 5*ax + 3*(max(v[N-2],v[N-1])-ax);

    cout << ans;
}