#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);


int main() {
    fastio;
    int N;
    cin >> N;
    int ans(0);

    while(N--) {
        string st;
        stack<char> s;
        cin >> st;
        for(int i = 0; i < st.size(); i++) {
            if(!s.empty() && s.top() == st[i]) {
                s.pop();
            }
            else s.push(st[i]);
        }

        if(s.empty()) ans++;
    }

    cout << ans;
}