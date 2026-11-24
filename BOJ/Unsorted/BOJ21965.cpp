#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto &x : v) cin >> x;

    int status = 0;
    for(int i = 1; i < N; i++) {
         if(v[i] == v[i-1]) {
            status = 2;
            break;
        }
        if(status == 0) {
            if(v[i] < v[i-1]) {
                status = 1;
            }
            else continue;
        }
        if(status == 1) {
            if(v[i] > v[i-1]) {
                status = 2;
                break;
            }
        }
    }

    if(status == 2) cout << "NO";
    else cout << "YES";
    
    return 0;
}