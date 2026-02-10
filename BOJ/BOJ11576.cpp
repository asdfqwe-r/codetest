#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    int m;
    cin >> a >> b;
    cin >> m;
    vector<int> v1;
    vector<int> v2;

    int idx10 = 0;

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    reverse(v1.begin(), v1.end());

    int ex = 1;
    for(int i = 0; i < m; i++) {
        idx10 += ex*v1[i];
        ex *= a;
    }

    while(idx10) {
        v2.push_back(idx10%b);
        idx10 /= b;
    }
    reverse(v2.begin(), v2.end());

    for(int i = 0; i < v2.size(); i++) {
        cout << v2[i] << ' ';
    }

    return 0;
}