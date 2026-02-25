#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    map<int,int> lad;
    map<int,int> sn;

    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        lad[x] = y;
    }

    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        sn[x] = y;
    }

    int vst[101] = {0,};
    queue<int> q;
    queue<int> cnt;
    q.push(1);
    cnt.push(0);
    while(!q.empty()) {
        int temp = q.front();
        int tempcnt = cnt.front();
        q.pop();
        cnt.pop();

        if(temp == 100) {
            cout << tempcnt;
            return 0;
        }

        for(int i = 1; i < 7; i++) {
            int ntemp = temp + i;

            if(vst[ntemp] == 1 || ntemp > 100) continue;

            
            if(sn.find(ntemp) != sn.end()) {
                vst[ntemp] = 1;
                ntemp = sn[ntemp];
                vst[ntemp] = 1;
                q.push(ntemp);
                cnt.push(tempcnt+1);
            }
            else if(lad.find(ntemp) != lad.end()) {
                vst[ntemp] = 1;
                ntemp = lad[ntemp];
                vst[ntemp] = 1;
                q.push(ntemp);
                cnt.push(tempcnt+1);
            }
            else {
                vst[ntemp] = 1;
                q.push(ntemp);
                cnt.push(tempcnt+1);
            }
        }
    }


}
// 알고리즘: BFS, 뱀과 사다리 게임, map
