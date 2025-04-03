#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a,int b) {
    if(b == 0) return a;
    return gcd(b,a%b); 
}

//Extended_Euclidean
tuple<ll,ll,ll> solve(int k, int c) {
    if(k == c) return make_tuple(0,1,c);

    ll a1(1),b1(0),r1(k),a2(0),b2(1),r2(c);
    ll at,bt,rt;
    while(r2 != 0) {
        ll q = r1/r2;
        rt = r1%r2;
        at = a1-a2*q;
        bt = b1-b2*q;

        r1 = r2,a1=a2,b1=b2;
        r2=rt,a2=at,b2=bt;

    }
    return make_tuple(a1,b1,r1);

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k,c;
        cin >> k >> c;
        if(gcd(k,c) != 1) cout << "IMPOSSIBLE" <<'\n';
        else {
            ll ans = get<1>(solve(k,c));
            if(ans <= 0) ans += k;
            if(c == 1) {
                ans = k+1;
            }
            if(ans > 1000000000) cout << "IMPOSSIBLE" << '\n';
            else cout << ans << '\n';
        }

    }
}