#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int ChkPos(int x) {
    int idx = 0;
    for(auto a : v) {
        if(a.second == x) break;
        idx++;
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt","r",stdin);
    int N,M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if(s == "order") {
            int t,n;
            cin >> n >> t;
            v.push_back({t,n});
        }
        if(s == "sort") {
            sort(v.begin(), v.end());
        }
        if(s == "complete") {
            int x;
            cin >> x;
            v.erase(v.begin()+ChkPos(x));
        }

        if(v.empty()) cout << "sleep\n";
        else {
            for (auto x : v) {
                cout << x.second << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}