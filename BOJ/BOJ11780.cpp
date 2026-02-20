#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[101]; //w,node
int arr[101][101];
int nxt[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    memset(arr, 0x3f, sizeof(arr));

    for(int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});

        if(w < arr[a][b]) {
            arr[a][b] = w;
            nxt[a][b] = b;
        }

        arr[a][b] = min<int>(arr[a][b],w);
    }

    for(int i=1; i <= n; i++)
        arr[i][i] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(arr[j][k] > arr[j][i] + arr[i][k]) {
                    arr[j][k] = arr[j][i] + arr[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] > 1e7) cout << 0 << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                cout << 0 << '\n';
                continue;
            }
            if(arr[i][j] > 1e7) {
                cout << 0 <<'\n';
                continue;
            }

            int idx = i;
            vector<int> v;
            while(idx != j) {
                v.push_back(idx);
                idx = nxt[idx][j];
            }
            v.push_back(j);

            cout << v.size() << ' ';
            for(int k = 0; k < v.size(); k++) {
                cout << v[k] << ' ';
            }
            cout << '\n';
        }
    }


    
    

    return 0;
}