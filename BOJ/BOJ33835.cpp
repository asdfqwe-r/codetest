#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll int n;
    cin >> n;
    ll int x1,y1,x2,y2;
    for(int i = 0; i < n; i++) {
        ll int x,y; 
        cin >> x >> y;
        if(i == 0) {
            x1 = x;
            y1 = y;
        }
        if(i == n-1) {
            x2 = x;
            y2 = y;
        }
    }

    double dist;
    dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    cout << dist;
}