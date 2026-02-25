#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int Cons = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == 'O') {
                Cons++;
                ans += Cons;
            }
            else {
                Cons = 0;
            }
        }
        cout << ans << '\n';
    }
}
// 알고리즘: 구현 (OX 점수 계산)
