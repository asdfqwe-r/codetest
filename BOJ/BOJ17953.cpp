#include <bits/stdc++.h>
using namespace std;

int arr[100001][11];
int DP[100001][11];

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[j][i];
        }
    }    

    memset(DP,-1,sizeof(DP));

    for(int i = 0; i < m; i++) {
        DP[0][i] = arr[0][i];
    }
    //DP
    for(int i = 1; i < n; i++) {
        int maxDP = -1;
        int maxidx = -1;
        for (int j = 0; j < m; j++) {
            if(DP[i-1][j] > maxDP) {
                maxDP = DP[i-1][j];
                maxidx = j;
            }
        }
        
        for(int j = 0; j < m; j++) {
            if(j == maxidx) continue;
            DP[i][j] = maxDP + arr[i][j];
        }
        int temp = -1;
        for(int j = 0; j < m; j++) {
            if(j == maxidx) continue;
            if(DP[i-1][j] > temp) {
                temp = DP[i-1][j];
            }
        }
        DP[i][maxidx] = maxDP+arr[i][maxidx]/2 > temp + arr[i][maxidx] ? maxDP+arr[i][maxidx]/2 : temp + arr[i][maxidx];
    }
/*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
*/
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = ans > DP[n-1][i] ? ans : DP[n-1][i];
    }
    cout << ans;

}