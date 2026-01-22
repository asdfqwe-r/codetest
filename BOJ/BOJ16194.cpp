#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int DP[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        DP[i] = 1<<30;
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j+i <= n; j++) {
            int temp = DP[i] + arr[j];
            if(DP[i+j] > temp) DP[i+j] = temp;
        }
    }

    cout << DP[n];

}
