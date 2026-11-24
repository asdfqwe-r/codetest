#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int Q;
    cin >> Q;
    while(Q--) {
        int cx;
        cin >> cx;

        if(cx == 1) {
            int x;
            cin >> x;
            if(x == 1) sort(v.begin(), v.end());
            else if(x == 2) sort(v.begin(), v.end(), greater<int>());
        }
        if(cx == 2) {
            int pos, x;
            cin >> pos >> x;
            v.emplace(v.begin()+pos, x);
        }
    }

    cout << v.size() << '\n';
    for (auto x : v) {
        cout << x << ' ';
    }
    
    return 0;
}