#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("input.txt","r",stdin);

    int K;
    cin >> K;

    for(int i = 1; i <= K; i++) {
        string s;
        int idx;
        cin >> idx;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(idx == 0) break;
            if(s[j] == 'b') {
                idx--;
            }
            if(s[j] == 'c') {
                idx++;
            }
        }
        cout << "Data Set " << i <<':' <<'\n';
        cout << idx << '\n';
        cout << '\n';
    }
    
    return 0;
}