#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;

    int N,S;
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int lt(0), rt(0);
    int sum = v[0];
    int ex = 1e5+1;
    while(rt < N) {
        if(sum < S) {
            rt++;
            sum += v[rt];
        }
        else {
            ex = min<int>(ex,rt-lt+1);
            sum -= v[lt];
            lt++;
        }
    }

    if(ex > 1e5) cout << 0;
    else cout << ex;
    
    return 0;
}
// 알고리즘: 투포인터 (Two Pointers), 슬라이딩 윈도우
