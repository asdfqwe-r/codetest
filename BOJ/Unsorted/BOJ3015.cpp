#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

stack<pair<int,int>> s;
int N;
ll ans = 0;

int main() {
    fastio;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        int cnt = 1;
        while(!s.empty() && s.top().X <= x) {
            ans += s.top().Y;
            if (s.top().X == x) cnt += s.top().Y;
            s.pop(); 
        }
        if(!s.empty()) ans++;
        s.push({x, cnt});
    } 

    cout << ans;
}