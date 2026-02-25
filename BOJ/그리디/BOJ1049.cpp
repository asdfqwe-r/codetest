#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    int a(2000),b(2000);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        a = min<int>(x,a);
        b = min<int>(y,b);
    }

    int ans;

    if(a > b*6) {
        ans = b*n;
    }
    else {
        ans = min<int>(a*(n/6)+b*(n%6), a*(n/6+1));
    }

    cout << ans;
    
    return 0;
}
// 알고리즘: 그리디, 정렬
