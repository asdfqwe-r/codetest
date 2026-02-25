#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
int dist[200001];
int cnt[200001];
queue<int> q;

int main() {

    memset(dist,-1,sizeof(dist));

    int ans1,ans2;
    cin >> n >> k;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    
    while(!q.empty()) {
        int tPos = q.front();

        q.pop();

        if(tPos == k) {
            ans1 = dist[tPos];
            ans2 = cnt[tPos];
            break;
        }

        int nPos[3] = {tPos-1,tPos+1,2*tPos};
        for(int i = 0; i < 3; i++) {
            if(nPos[i] < 0 || nPos[i] > 200000) continue;
            if(dist[nPos[i]] == -1) {
                dist[nPos[i]] = dist[tPos] + 1;
                cnt[nPos[i]] = cnt[tPos];
                q.push(nPos[i]);
            }
            if(dist[nPos[i]] == dist[tPos] + 1) {
                cnt[nPos[i]] += cnt[tPos];
            }
            if(dist[nPos[i]] > dist[tPos] + 1) {
                continue;
            }

        }
       
    }    

    cout << ans1 << '\n' << ans2;
    return 0;
}
// 알고리즘: BFS, 최단거리 + 경우의 수
