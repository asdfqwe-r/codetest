#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second


deque<pair<int,int>> dq;

int main() {
    fastio;
    int N, L;
    cin >> N >> L;

    for(int i = 1; i <= N; i++) {
        int ax;
        cin >> ax;
        
        while(!dq.empty() && dq.front().Y <= i-L) {
            dq.pop_front();
        }

        while(!dq.empty() && dq.back().X > ax) {
            dq.pop_back();
        }
        dq.push_back({ax,i});
        cout << dq.front().X << ' ';
    }
}