#include<bits/stdc++.h>
using namespace std;

int arr[2003];

int main() {
    int n,l;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[2*x] = arr[2*x-1] = 1;
    }

    l *= 2;

    int ans = 0;
    for (int i = 0; i < 2003; i++) {
        if(arr[i] == 1) {
            for(int j = 0; j < l; j++) {
                arr[i+j] = 0;
            }
            ans++;
            i += l-1;
        }
    }

    cout << ans;

    

}