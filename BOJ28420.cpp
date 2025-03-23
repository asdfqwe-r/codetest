#include<iostream>
using namespace std;

int arr[301][301];
int sum[302][302];

int main() {
    int n,m,a,b,c;
    cin >> n >> m;
    cin >> a >> b >> c;

    int ans = 10000001;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i-1][j-1];
        }
    }

    //Case 1
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int tmp = 0;
            if(i+a >= n+2) continue;
            if(j+b+c >= m+2) continue;
            tmp = sum[i+a-1][j+b+c-1] - sum[i-1][j+b+c-1] - sum[i+a-1][j-1] + sum[i-1][j-1];
            ans = min(tmp,ans);
        }
    }

    //Case 2
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i+a+b >= n+2) continue;
            if(j+a+c >= m+2) continue;
            int tmp1 = sum[i+a-1][j+c-1] - sum[i-1][j+c-1] - sum[i+a-1][j-1] + sum[i-1][j-1];
            int tmp2 = sum[i+a+b-1][j+c+a-1] - sum[i+a-1][j+c+a-1] - sum[i+a+b-1][j+c-1] + sum[i+a-1][j+c-1];
            ans = min(tmp1+tmp2,ans);
        }
    }

    //Case 3
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i+a+c >= n+2) continue;
            if(j+a+b >= m+2) continue;
            int tmp1 = sum[i+a-1][j+b-1] - sum[i-1][j+b-1] - sum[i+a-1][j-1] + sum[i-1][j-1];
            int tmp2 = sum[i+a+c-1][j+b+a-1] - sum[i+a-1][j+b+a-1] - sum[i+a+c-1][j+b-1] + sum[i+a-1][j+b-1];
            ans = min(tmp1+tmp2,ans);
        }
    }

    cout << ans;




}