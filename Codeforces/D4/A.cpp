#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 1; j <= x; j++) {
            cout << j << ' ';
        }
        cout << endl;
    }

}