#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt","r",stdin);

    int n;
    cin >> n;

    int H(0),HR(0),F(0);
    vector<long long int> v;
    for(int i = 0; i < n; i++) {
        long long int x,y;
        cin >> x >> y;
        if(!(x+y >= 0 && y-x >= 0)) {
            F++;
            continue;
        }
        v.push_back(x*x+y*y);
    }

    int q;
    cin >> q;

    sort(v.begin(), v.end());

    while(q--) {
        long long int r;
        cin >> r;
        r = r*r;

        int idx = upper_bound(v.begin(), v.end(), r) - v.begin();

        cout << F << ' ' << idx << ' ' << v.size()-idx << '\n';

    }
    
    return 0;
}