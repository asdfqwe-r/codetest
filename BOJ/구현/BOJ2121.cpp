#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<pair<int,int>> s;

int main() {
    
    int n;
    int a,b;
    cin >> n;
    cin >> a >> b;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        s.insert({x,y});
    }


    int cnt = 0;

    for(auto x : s) {
        int tempx = x.first;
        int tempy = x.second;

        //Sq2
        bool flag = true;
        int movX1[4] = {0,0,a,a};
        int movY1[4] = {0,b,0,b};
        for(int i = 0; i < 4; i++) {
            auto it = s.find({tempx+movX1[i],tempy+movY1[i]});
            if(it == s.end()) {
                flag = false;
                break;
                
            }
        }
        if(flag) cnt++;

    }

    cout << cnt;

}
// 알고리즘: set, 구현 (직사각형 개수)
