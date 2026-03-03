#include <bits/stdc++.h>
using namespace std;

int cnt_LIMIT, idx_LIMIT;

int gcd(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int solve(pair<int,int> x, int idx, int cnt, int bf) {
    auto [p,q] = x;
    if(p == 0) return 1;
    if(cnt == cnt_LIMIT) return 0;

    int st = max(bf, (p+q-1)/p);
    int en = min(idx_LIMIT/idx, (cnt_LIMIT - cnt)*q/p);

    int ex = 0;

    for(int i = st; i <= en; i++) {
        int nxt_p = p*i-q;
        int nxt_q = q*i;

        int g = gcd(nxt_p,nxt_q);
        nxt_p /= g;
        nxt_q /= g;


        ex += solve(make_pair(nxt_p,nxt_q), idx*i, cnt+1, i);
    }

    return ex;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int p,q;
    cin >> p >> q >> idx_LIMIT >> cnt_LIMIT;

    int g = gcd(p,q);
    p /= g;
    q /= g;

    cout << solve(make_pair(p,q), 1, 0, 1) ;
    
    return 0;
}