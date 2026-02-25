#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    int arr[4] = {25,10,5,1};
    while(t--) {
        int c;
        vector<int> v(4);
        cin >> c;
        for(int i = 0; i < 4; i++) {
            v[i] = c/arr[i];
            c %= arr[i];
        }

        for(int i = 0; i < 4; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
// 알고리즘: 그리디 (동전 거스름돈)
