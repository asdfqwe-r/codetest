#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            if (a < 0 && b < 0 && c < 0) {
                continue;
            }
            sum += max<int>(max<int>(a,b),c);
        }

        cout << sum << '\n';
    }
    
    return 0;
}