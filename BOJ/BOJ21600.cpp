#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }


    int lt(0), rt(0);
    int MaxLen(-1);

    while(rt < n) {
        int NowLen = rt-lt+1;
        
        if(v[rt] >= NowLen) {
            MaxLen = max<int>(MaxLen, NowLen);
            rt++;
            continue;
        }
        else {
            lt++;
        }
        
    }

    cout << MaxLen;


    
    return 0;
}