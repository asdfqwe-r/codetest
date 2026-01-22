#include<bits/stdc++.h>
#define ll long long 
using namespace std;
typedef pair<int,int> ii;

int main() {
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    ii v1 = {x2-x1,y2-y1};
    ii v2 = {x3-x2,y3-y2};

    int ans = v1.first*v2.second - v1.second*v2.first;

    if(ans > 0) {
        cout << 1;
    }
    else if (ans == 0) {
        cout << 0;
    }
    else {
        cout << -1;
    }
}