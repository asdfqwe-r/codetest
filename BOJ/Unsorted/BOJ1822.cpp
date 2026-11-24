#include <bits/stdc++.h>
using namespace std;
set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    cin >> a >> b;

    for(int i = 0; i < a; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for(int i = 0; i < b; i++) {
        int x;
        cin >> x;
        if(s.find(x) != s.end()) {
            s.erase(s.find(x));
        }
    }

    cout << s.size() << '\n';
    if(s.size() == 0) exit(0);
    for(auto x : s) {
        cout << x << ' ';
    }
    
    return 0;
}