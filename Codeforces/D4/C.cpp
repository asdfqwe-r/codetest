#include<bits/stdc++.h>
using namespace std;
//가장 긴 연속 수열

int main() {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        vector<int> v;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        

        int ans = 0;
        int idx = 0;
        int cmp = v[0]-1;
        for(int i = 0; i < v.size(); i++) {
            if(cmp + 1 == v[i]) {
                idx++;
            }
            else{
                ans = idx>ans?idx:ans;
                idx = 1;
            }
            cmp = v[i];
        }
        ans = idx>ans?idx:ans;

        cout << ans << '\n';
    }

}