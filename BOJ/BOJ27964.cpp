#include<bits/stdc++.h>
using namespace std;

vector<string> sarr;
int CheeseChk(string s) {
    int len = s.size();
    if(s[len-6] == 'C' && s[len-5] == 'h') {}
    else {
        return 0;
    }
    if(s[len-4] == 'e' && s[len-3] == 'e') {}
    else {
        return 0;
    }
    if(s[len-2] == 's' && s[len-1] == 'e') {}
    else {
        return 0;
    }

    for(auto x : sarr) {
        if (x == s) {
            return 0;
            break;
        }
    }

    sarr.push_back(s);

    return 1;
}


int main() {
    int n;
    cin >> n;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        cnt += CheeseChk(temp);
        
    }

    if(cnt >= 4) cout << "yummy\n";
    else cout << "sad";

    
}