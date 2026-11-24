#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int N;
stack<pair<int,int>> s;

int main() {
    fastio;
    freopen("input.txt","r",stdin);

    cin >> N;

    s.push({100000001, 0});
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if(s.top().first >= x) {
            cout << s.top().second << ' ';
            s.push({x,i});
        }
        else {
            while(s.top().first < x) {
                s.pop();
            }
            cout << s.top().second << ' ';
            s.push({x,i});
        }
    }

}

