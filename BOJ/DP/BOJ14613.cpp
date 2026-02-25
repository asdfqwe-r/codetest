#include <bits/stdc++.h>
using namespace std;

double DP[21][3500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    double w,l,d;
    cin >> w >> l >> d;
    DP[0][2000] = 1;
    for(int i = 0; i < 20; i++) {
        for(int j = 1000; j <= 3500; j+= 50) {
            DP[i+1][j+50] += DP[i][j]*w;
            DP[i+1][j] += DP[i][j]*d;
            DP[i+1][j-50] += DP[i][j]*l;
        }
    }

    for(int i = 0; i < 5; i++) {
        double ans = 0;
        for(int j = 1000+500*i; j < 1499+500*i; j+=50) {
            ans += DP[20][j];
        }
        
        cout.setf(ios::fixed);
        cout.precision(8);
        cout << ans << '\n';
    }
    return 0;
}
// 알고리즘: DP (확률 DP)
