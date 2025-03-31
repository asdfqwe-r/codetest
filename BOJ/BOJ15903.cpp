#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int arr[1001];
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> arr[i];
    }

    sort(arr,arr+n);

    for(int i = 0; i < m; i++) {
        long long int x,y;
        x = arr[0];
        y = arr[1];
        arr[0] = arr[1] = x+y;
        sort(arr,arr+n);
    }

    long long int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    cout << sum;

}