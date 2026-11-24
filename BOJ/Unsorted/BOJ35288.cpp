#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int N;
        string s;
        cin >> N >> s;
        int ex = 0;
        for(auto x : s) {
            ex += x -'0';
        }
        if(N == 1) {
            cout << "9 3\n";
            continue;
        }

        int idx = 0;
        bool flag = 1;
        for(int i = 0; i < s.length() && flag; i++) {
            for(int j = 1; j <= 9 && flag; j++) {
                if(((ex + j -(s[i]-'0')) %3 == 0)&& !(j == s[i]-'0')) {
                    idx++;
                    for(int k = 0; k < s.length() && flag; k++) {
                        if(k == i) cout << j;
                        else cout << s[k];
                    }
                    cout << " 3" << '\n';
                    if(idx == N) flag = 0;
                }
            }
        }

    }
    
    return 0;
}