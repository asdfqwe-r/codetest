#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int cnt[9] = {0,};
        int n;
        cin >> n;
        int ans = 0;
        int flag = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if(flag == 1) continue;
            if(cnt[0] > 2 && cnt[1] > 0 && cnt[2] > 1 && cnt[3] > 0 && cnt[5] > 0) {
                flag = 1;
                ans = i+1;
            }
        }
        cout << ans << '\n';
    }

}