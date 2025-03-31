#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll memo[2001][2001];
int m;

ll comb(int n, int k) {
    if(n < k) return 0;
    if(n/2 < k) k = n-k;

    if(n == k) return 1;
    if(k == 0) return 1;
    if(k == 1) return n;

    if(memo[n][k] == -1) {
        memo[n][k] = (comb(n-1,k-1)+comb(n-1,k))%m;
        return memo[n][k];
    }
    else return memo[n][k];
    
}


int main() {
    memset(memo,-1,sizeof(memo));
    
    ll n,k;
    cin >> n >> k >> m;
    ll ans = 1;

    //Lucas' Theorem
    while(n && k) {
        ans *= comb(n%m,k%m);
        ans %= m;
        n /= m;
        k /= m;
    }


    cout << ans;
}