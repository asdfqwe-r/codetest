#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    vector<int> v[101];

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if(x == 1) {
                v[i].push_back(j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int det = 0;
            
            queue<int> q;
            int vst[101] = {0,};
            for(auto x : v[i]) {
                q.push(x);
            }

            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                if(temp == j) {
                    det = 1;
                    break;
                }
                for(auto y : v[temp]) {
                    if(vst[y] == 0) {
                    q.push(y);
                    vst[y] = 1;
                    }
                }
            }
            cout << det << ' ';
        }
        cout << '\n';
    }

}