#include <bits/stdc++.h>
using namespace std;

int MAX = 1000000000;
int DP[1201];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //0,1 Knapsack
    int c,n;
    cin >> c >> n;

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for(int i = 0; i < 1200; i++) {
        DP[i] = MAX;
    }

    DP[0] = 0;

    for(int i = 0; i <= c; i++) {
        for(int j = 0; j < n; j++) {
            DP[i+v[j].second] = DP[i+v[j].second]>DP[i]+v[j].first?DP[i]+v[j].first:DP[i+v[j].second];
        }
    }

    int ans = MAX;

    for(int i = c; i <= c+100; i++) {
        ans = min<int>(ans,DP[i]);
    }

    cout << ans;

    return 0;
}