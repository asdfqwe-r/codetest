#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;


int n;
int DP[2223][2223];
int arr[2223][2223];

int main() {
    
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                continue;
            }

            if(i == 0) {
                DP[i][j] = DP[i][j-1] + max(arr[i][j]-arr[i][j-1]+1,0);
                continue;
            }

            if(j == 0) {
                DP[i][j] = DP[i-1][j] + max(arr[i][j]-arr[i-1][j]+1,0);
                continue;
            }

            int comp1 = DP[i-1][j] + max(arr[i][j] - arr[i-1][j] +1, 0);
            int comp2 = DP[i][j-1] + max(arr[i][j] - arr[i][j-1] +1,0);

            DP[i][j] = min(comp1,comp2);
        }
    }

    cout << DP[n-1][n-1];
    
}