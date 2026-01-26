#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int arr[200001];
    cin >> n;
    if(n%2 == 0) {
        for(int i = 0; i < n/2; i++) {
            arr[n/2+i] = n-2*i;
            arr[n/2-i-1] = n-2*i-1;
        }
    }
    else {
        arr[(n-1)/2] = n;
        for(int i = 0; i < n/2; i++) {
            arr[(n+1)/2+i] = n-2*i-1;
            arr[(n-3)/2-i] = n-2*i-2;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    
}