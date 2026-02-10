#include <bits/stdc++.h>
using namespace std;

int arr[5000];

int main() {
    
    //freopen("input.txt","r",stdin);

    int n,m,k;
    cin >> n >> m >> k;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d",&arr[j]);
        }
        int idx = 0;
        for(int j = 0; j < m; j++) {
            if(arr[j] == 0) {
                idx++;
            }
            else {
                if(idx >= k) ans += idx-k+1;
                idx = 0;
            }
        }
        if(idx >= k) ans += idx-k+1;
        else continue;
    }

    cout << ans;
    
    return 0;
}