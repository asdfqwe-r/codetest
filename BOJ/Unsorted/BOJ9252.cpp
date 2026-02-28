#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s1,s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> DP(n+1, vector<int>(m+1,0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else {
                DP[i][j] = max<int>(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    string ans = "";
    int x(n), y(m);

    while(x > 0 && y > 0) {
        if(s1[x-1] == s2[y-1]) {
            ans += s1[x-1];
            x--;
            y--;
        }
        else if(DP[x][y-1] > DP[x-1][y]) {
            y--;
        }
        else {
            x--;
        }
    }

    reverse(ans.begin(), ans.end());

    if(DP[n][m] == 0) {
        cout << 0;
        return 0;
    }
    cout << DP[n][m] << '\n';
    cout << ans;
    
    return 0;
}