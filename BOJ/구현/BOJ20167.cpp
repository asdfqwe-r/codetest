#include <bits/stdc++.h>
using namespace std;

int pow2[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ex(1);
    for(int i = 0; i < 21; i++) {
        pow2[i] = ex;
        ex *= 2;
    }

    int n,k;
    vector<int> v;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    int ans = -1;

    for(int i = 0; i < pow2[n]; i++) {
        int idx = i;
        int NowE(0), comp(0);
        for(int j = 0; j < n; j++) {
            if(NowE != 0 && !(idx%2)) {
                comp = 0;
                break;
            }
            if(!(idx%2)) {
                idx /= 2;
                continue;
            }
            NowE += v[j];
            if(NowE >= k) {
                comp += NowE-k;
                NowE = 0;
            }
            idx /= 2;
        }
        ans = max<int>(ans, comp);
    }

    cout << ans;
    
    return 0;
}
// 알고리즘: 브루트포스, 비트마스크 (부분집합)
