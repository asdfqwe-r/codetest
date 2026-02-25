#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;
    int pos = -1;
    for(int i = 0; i < 13; i++) {
        char x;
        cin >> x;
        if(x == '*') {
            v.push_back(0);
            pos = i;
        }
        else v.push_back(x-'0');
    }
    int mod = 0;
    for(int i = 0; i < 13; i++) {
        if(i%2 == 1) {
            mod += 3*v[i];
        }
        else mod += v[i];
    }
    mod %= 10;
    if(mod != 0) {
        mod = 10-mod;
    }

    if(pos%2==0) {
        cout << mod;
    }
    else {
        while(mod%3 != 0) {
            mod += 10;
        }
        cout << mod/3;
    }


    
}
// 알고리즘: 구현, 바코드 체크섬 (수학)
