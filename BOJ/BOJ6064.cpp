#include<iostream>
using namespace std;
using ll = long long;
ll modInverse(ll a, ll m) {
    for(int i = 1; i < m; i++) {
        if((long long)(a*i) % (long long)m == 1) {
            return i;
        }
    }
    return 0;
}

ll gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll lcm (ll a, ll b) {
    return a*b/gcd(a,b);
}

//Chinese Remainder Theorem
ll f(ll m, ll n, ll x, ll y) {
    ll M = m*n;
    ll n1 = M/m;
    ll n2 = M/n;

    ll s1 = modInverse(M/m,m);
    ll s2 = modInverse(M/n,n);

    //cout << n1 << ' ' << n2 << ' ';
    ll fnl = ((n1*s1*x)%M+(n2*s2*y)%M)%M;
    return fnl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        ll m,n,x,y;
        cin >> m >> n >> x >> y;
        
        if(m == x && n == y) {cout << lcm(m,n) << '\n'; continue;}

        if((y-x)%gcd(m,n) != 0) {
            cout << "-1" << '\n';
            continue;
        }
        
        if(gcd(m,n) != 1) {
            if(x > y) {
                ll ex = gcd(m,n);
                cout << f(m/ex,n/ex,(x-y)/ex,0)*ex+y << '\n';
            }
            else {
                ll ex = gcd(m,n);
                cout << f(m/ex,n/ex,0,(y-x)/ex)*ex+x << '\n';
            }
            continue;
        }
        
        
        cout << f(m,n,x,y) << '\n';
    }


}


