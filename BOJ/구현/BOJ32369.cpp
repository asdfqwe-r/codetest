#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
    int n,a,b,x,y;
    cin >> n >> a >> b;

    x = 1; y = 1;
    for(int i = 0;i < n; i++) {
        x += a;
        y += b;

        if(y > x) {
            int temp = x;
            x = y;
            y = temp;
        }
        else if(y == x) {
            y -= 1;
        }

    }

    cout << x << ' ' << y;
}
// 알고리즘: 구현 (순열 배치 패턴)
