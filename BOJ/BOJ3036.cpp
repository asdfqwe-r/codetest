#include<bits/stdc++.h>
#define ii pair<long long,long long>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}


ii frac(ii p) {
    ll x = p.first;
    ll y = p.second; 
    
    ll g = gcd(p.first,p.second);
    ii ret = make_pair(x/g,y/g);

    return ret;
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x : v) cin >> x;

    ii temp;

    for(int i = 1; i < n; i++) {
        
        temp = frac({v[0],v[i]});
        cout << temp.first << '/' << temp.second << '\n';

    }


}