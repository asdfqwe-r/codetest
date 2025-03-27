#include<bits/stdc++.h>
using namespace std;

long long int memo[10000001];

long long int PrimeNum(int n) {
    if(n < 2) return 0;
    else if(memo[n]) return memo[n];
    else {
    int cnt = 0;
    vector<bool> isP(n+1,true);
    isP[0] = isP[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(isP[i]) {
            for(int j = i*i; j <= n; j += i) {
                isP[j] = false;
            } 
        }
    }

    for(bool x : isP) {
        if(x == true) cnt++;
    }
    memo[n] = cnt;
    return cnt;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long int ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            ans += PrimeNum(n/i);
        }
        cout << ans <<'\n';
    }
}