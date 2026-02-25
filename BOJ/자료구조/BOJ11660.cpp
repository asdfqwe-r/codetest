#include<bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


int n,m;
ll sum[1025][1025];
int arr[1025][1025];


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            sum[i][j] += (ll)arr[i][j];
        }
    }

    while(m--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        cout << ans << '\n';
    }

    
}
// 알고리즘: 2D 누적합 (2D Prefix Sum)
