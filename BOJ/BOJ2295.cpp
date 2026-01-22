#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;
int sum[1000000];
int arr[1001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            sum[idx] = arr[i] + arr[j];
            idx++;
        }
    }

    sort(sum,sum+idx);
    
    int ans = 0;
    bool flag = false;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i-1; j >= 0; j--) {
            int temp = arr[i]-arr[j];
            flag = binary_search(sum,sum+idx,temp);
            //cout << temp << ' ';

            if(flag) {
                ans = arr[i];
                break;
            }
        }
        if(flag) {
            break;
        }
    }

    cout << ans;
}
