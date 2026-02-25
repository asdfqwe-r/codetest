#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt","r",stdin);
    
    int N;
    cin >> N;

    stack<int> s;
    int ans = 0;
    int idx = 0;

    for(int i = 0; i < N; i++) {
        char x;
        int a;
        cin >> x;
        if(x == '(') a = 0;
        else a = 1;

        if(!s.empty()) {
            if(s.top() == !a) {
                s.pop();
            }
            else {
                s.push(a);
                ans = max<int>(ans,s.size());
            }
        }
        else {
            s.push(a);
            ans = max<int>(ans,s.size());
        }

    }
    
    if(!s.empty()) {
        cout << -1;
    }
    else cout << ans;

    return 0;
}
// 알고리즘: 스택 (Stack), 괄호 문자열 처리
