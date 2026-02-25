#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;
    string sarr[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};

    for(int j = 0; j < 3; j++) {
        string ex;
        cin >> ex;
        for(int i = 0; i < 10; i++) {
            if(sarr[i] == ex) {
                v.push_back(i);
                break;
            }
        }
    }   

    long long idx = 1;
    for(int i = 0; i < v[2]; i++) {
        idx *= 10;
    }

    cout << (long long)(v[0] * 10 + v[1]) * idx;
    return 0;
}


// 알고리즘: 구현, 문자열 매핑 (저항 색코드)
