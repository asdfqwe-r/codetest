#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int N;
stack<pair<int,int>> s;
ll sum = 0;
int ax;

int main() {
    fastio;
    //freopen("input.txt","r",stdin);
    cin >> N;
    cin >> ax;
    s.push({ax,1});
    for(int i = 2; i <= N; i++) {
        int x;
        cin >> x;
        if(s.top().first > x) {
            s.push({x,i});
        }
        else {
            while(!s.empty() && s.top().first <= x ) {
                sum += i-s.top().second-1;
                s.pop();
            }
            s.push({x,i});
        }
    }

    while(!s.empty()) {
        sum += N-s.top().second;
        s.pop();
    }

    cout << sum;
}