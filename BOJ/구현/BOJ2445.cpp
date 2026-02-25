#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < n; j++) {
            if(j < i+1) cout << '*';
            else cout << ' ';
        }
        for(int j = 0; j < n; j++) {
            if(j > n-i-2) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    for(int i = n-2; i >= 0; i--) {
        
        for(int j = 0; j < n; j++) {
            if(j < i+1) cout << '*';
            else cout << ' ';
        }
        for(int j = 0; j < n; j++) {
            if(j > n-i-2) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}
// 알고리즘: 구현 (별 찍기, 패턴 출력)
