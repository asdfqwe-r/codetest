#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,s;
    cin >> n >> s;
    
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int max = 1 << v.size();

    int ans = 0;
    for(int i = 1; i < max; i++) {
        int idx = i;
        int sum = 0;
        int cnt = 0;
        while(idx) {
            if(idx%2 == 1) {
                sum += v[cnt];
            }
            idx /= 2;
            cnt++;
        }

        if(sum == s) {
        ans++;
        }
    }

    cout << ans;
}