#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, long long> mp;

    long long b,n,m;
    cin >> b >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        long long x;
        cin >> s >> x;
        mp.insert({s,x});

    }

    long long sum = 0;

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        sum += (*mp.find(s)).second;
    }

    if(sum <= b) cout << "acceptable";
    else cout << "unacceptable";
    
    
    return 0;
}