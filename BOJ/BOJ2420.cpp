#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long a,b;
    cin >> a >> b;

    long long ans = a>b?a-b:b-a;
    cout << ans;
    
    return 0;
}