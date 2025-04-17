#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}

int main() {
    int n;
    cin >> n;

    ll arr1[50] = {0,};
    ll arr2[50] = {0,};

    if(n == 1) {
        int x,y;
        cin >> x >> y;
        int ax = gcd(x,y);

        cout << x/ax << ' ' << y/ax;
        return 0;
    }


    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        int ex = gcd(x,y);
        if(gcd(x,y) != 1) {
            x /= ex;
            y /= ex;
        }
        arr1[i] = x;
        arr2[i] = y;
    }

    ll ans2 = lcm(arr2[0],arr2[1]);

    for(int i = 2; i < n; i++) {
        ans2 = lcm(ans2,arr2[i]);
    }

    for(int i = 0; i < n; i++) {
        ll temp = ans2/arr2[i];
        arr1[i] = arr1[i]*temp;
    }

    ll ans1 = gcd(arr1[0],arr1[1]);

    for(int i = 2; i < n; i++) {
        ans1 = gcd(ans1,arr1[i]);
    }

    int ex2 = gcd(ans1,ans2);
    if(gcd(ans1,ans2) != 1) {
        ans1 /= ex2;
        ans2 /= ex2;
    }

    cout << ans1 << ' ' << ans2;
}