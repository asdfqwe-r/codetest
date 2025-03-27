#include<bits/stdc++.h>
using namespace std;

bool compare(int i, int j) {
    return j < i;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n,x;
        cin >> n >> x;
        int cnt = 0;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int ex;
            cin >> ex;
            v.push_back(ex);
        }
        sort(v.begin(),v.end(),compare);
        int teamF = 0;
        int teamNum = 0;
        for(int i = 0; i < n; i++) {
            if(teamF == 0) {
                teamNum++;
                if(teamNum*v[i] >= x) teamF = 1;
            }
            if(teamF == 1) {
                teamNum = 0;
                cnt++;
                teamF = 0;
            }
        }
        

        
        cout << cnt << '\n';
    }
}