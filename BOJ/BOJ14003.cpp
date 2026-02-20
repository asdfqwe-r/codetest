#include <bits/stdc++.h>
using namespace std;

vector<int> low;
int idx[1000001];

vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for(int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back(x);
        int pos = lower_bound(low.begin(), low.end(), x) - low.begin();
        if(pos == low.size()) {
            low.push_back(x);
        }
        else {
            low[pos] = x;
        }
        idx[i] = pos;
    }

    cout << low.size() << '\n';

    vector<int> ans;
    int ex = low.size()-1;
    for(int i = N-1; i >= 0; i--) {
        if(idx[i] == ex) {
            ans.push_back(v[i]);
            ex--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' '; 

    return 0;
}