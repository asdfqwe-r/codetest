#include <bits/stdc++.h>
using namespace std;

vector<int> G[100001];

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x,y;
        cin >> x >> y;
        G[y].push_back(x);
    }

    long long int ans = 0;
    for(int i = 1; i < 100001; i++) {
        if(G[i].size() < 2) continue;
        sort(G[i].begin(), G[i].end());

        for(int j = 0; j < G[i].size(); j++) {
            if(j == 0) {
                ans += G[i][1] - G[i][0];
            }
            else if(j == G[i].size()-1) {
                int ex = G[i].size()-1;
                ans += G[i][ex] - G[i][ex-1];
            }
            else {
                ans += G[i][j+1]-G[i][j] > G[i][j] - G[i][j-1]?G[i][j] - G[i][j-1] : G[i][j+1]-G[i][j];
            }
        }
    }

    cout << ans;

}