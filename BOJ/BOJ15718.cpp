#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll memo1[2001][2001];
ll memo2[2001][2001];

ll comb1(int n,int k, int m) {
    if(n < k) return 0;
    if(n/2 < k) k = n-k;

    if(n == k) return 1;
    if(k == 0) return 1;
    if(k == 1) return n%m;
    
    if(memo1[n][k] == -1) {
        memo1[n][k] = (comb1(n-1,k-1,m)+comb1(n-1,k,m))%m;
        return memo1[n][k];
    }
    else return memo1[n][k];
}

ll comb2(int n,int k, int m) {
    if(n < k) return 0;
    if(n/2 < k) k = n-k;

    if(n == k) return 1;
    if(k == 0) return 1;
    if(k == 1) return n%m;
    
    if(memo2[n][k] == -1) {
        memo2[n][k] = (comb2(n-1,k-1,m)+comb2(n-1,k,m))%m;
        return memo2[n][k];
    }
    else return memo2[n][k];
}

ll lucas(int n, int k, int m) {
    ll ans = 1;

    while(n && k) {
        if(m == 97) ans *= comb1(n%m,k%m,m);
        if(m == 1031) ans *= comb2(n%m,k%m,m);
        ans %= m;
        n /= m;
        k /= m;
    }
    return ans;
}

ll modInverse(ll a,ll m) {
    for(int i = 1; i < m; i++) {
        if((long long)(a*i) % (long long)m == 1) {
            return i;
        }
    }
    return 0;
}

ll CRT(ll m, ll n, ll x, ll y) {
    ll M = m*n;
    ll n1 = M/m;
    ll n2 = M/n;

    ll s1 = modInverse(n1,m);
    ll s2 = modInverse(n2,n);

    ll ret = ((n1*s1*x)%M + (n2*s2*y)%M)%M;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    memset(memo1,-1,sizeof(memo1));
    memset(memo2,-1,sizeof(memo2));
    while(t--) {

        int n,m;
        cin >> n >> m;

        if(m == 1 && n == 0) {
            cout << 1 << '\n';
            continue;
        }
        if(m == 1) {
            cout << 0 << '\n';
            continue;
        }

        if(m-1 > n) {
            cout << 0 << '\n';
            continue;
        }

        ll rem1 = lucas(n-1,m-2,97);
        ll rem2 = lucas(n-1,m-2,1031);

        ll div1 = 97;
        ll div2 = 1031;

        //cout << rem1 << ' ' << rem2 << '\n';

        cout << CRT(div1,div2,rem1,rem2) << '\n';
    }
}