#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[6] = {1,1,2,2,2,8};
    for(int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        cout << arr[i]-x << ' ';
    }
    
    return 0;
}