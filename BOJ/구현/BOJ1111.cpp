#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    if(n == 1) {
        cout << 'A';
        return 0;
    }

    if(n == 2) {
        if(v[0] == v[1]) {
            cout << v[0];            
        }
        else cout << 'A';
        return 0;
    }

    bool flag = true;

    if(v[0] == v[1]) {
        for(int i = 0; i < n-1; i++) {
            if(v[i] != v[i+1]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << 'B';
            return 0;
        }
        else {
            cout << v[0];
            return 0;
        }
    }

        int a = (v[2]-v[1])/(v[1]-v[0]);
        int b = v[1]-a*v[0];
        
        for(int i = 1; i < n; i++) {
            if(v[i] != a*v[i-1]+b) {
                flag = 0;
                break;
            }
        }

        if (!flag) {
            cout << 'B';
        }
        else cout << a*v[n-1]+b;
    
}
// 알고리즘: 구현, 수열 패턴 인식 (등비/등차)
