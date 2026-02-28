#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //Two-Pointers
    int N;
    cin >> N;
    v.resize(N);
    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int lt(0),rt(N-1);
        while(lt < rt) {
            if(lt == i) {
                lt++;
                continue;
            }
            if(rt == i) {
                rt--;
                continue;
            }
            if(v[lt] + v[rt] > v[i]) {
                rt--;
            }
            else if(v[lt]+v[rt] < v[i]) {
                lt++;
            }
            else {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    
    return 0;
}