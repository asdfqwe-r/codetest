#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
    int a,b;
    string c;
    cin >> a >> b >> c;

    char ex = c[c.size()-1];
    int d = ex - '0';
    d %= 2;
    if(d == 0) {
        cout << a;
    }
    else {
        int temp = a ^ b;
        cout << temp;
    }

}