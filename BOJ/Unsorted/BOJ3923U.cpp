#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

pair<int,int> ExEuc(int a, int b, int d) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int a,b,d;
        cin >> a >> b >> d;
        if(!(a&&b&&d)) {
            break;
        }

    }
    
    return 0;
}