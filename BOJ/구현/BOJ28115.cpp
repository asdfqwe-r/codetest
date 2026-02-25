#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int d = v[1] - v[0];
    int flag = 1;
    for(int i = 1; i < n; i++) {
        if(v[i]-v[i-1] == d) {
            continue;
        }
        else {
            flag = 0;
        }
    }

    if(flag) {
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        for(int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
    }
    else {
        cout << "NO";
    }
    
    return 0;
}
// 알고리즘: 구현 (등차수열 확인)
