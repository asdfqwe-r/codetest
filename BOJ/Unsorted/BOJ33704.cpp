#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Ad-Hoc
    int N;
    cin >> N;

    v.resize(N);
    for (auto &x : v) cin >> x;

    if(N == 2) {
        if(v[0] > v[1]) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
    
    return 0;
}