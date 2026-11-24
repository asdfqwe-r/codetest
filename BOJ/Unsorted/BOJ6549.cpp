#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
stack<pair<ll,ll>> s;


int main() {
    fastio;
    
    while(1) {
        ll ans = 0;
        cin >> N;   
        if(N == 0) return 0;
        for(int i = 0; i < N; i++) {
            int h, idx(i);
            cin >> h;
            while(!s.empty() && s.top().X >= h) {
                ans = max(ans, (i-s.top().Y)*s.top().X);
                idx = s.top().Y;
                s.pop();
            }
            s.push({h,idx});
        }
        while(!s.empty()) {
            ans = max(ans, (N-s.top().Y)*s.top().X);
            s.pop();
        }
        cout << ans << '\n';
    }    

}