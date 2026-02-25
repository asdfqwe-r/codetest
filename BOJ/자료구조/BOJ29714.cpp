#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int,int> m;

int main() {
    int n,q;
    int cnt = n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(m.find(x) == m.end()) {
            m.insert({x,1});
        }
        else{
            m[x]++;
        }
    }
    
    cin >> q;
    while(q--) {
        int a,b;
        cin >> a;
        vector<int> va;
        vector<int> vb;
        for(int i = 0; i < a; i++) {
            int x;
            cin >> x;
            va.push_back(x);
        }
        cin >> b;
        for(int i = 0; i < b; i++) {
            int x;
            cin >> x;
            vb.push_back(x);
        }

        bool flag = true;
        for(int i = 0; i < a; i++) {
            if(m.find(va[i]) == m.end() || m[va[i]] == 0) {
                flag = false;
                for(int j = 0; j < i; j++) {
                    m[va[j]]++;
                }
                break;
            }
            m[va[i]]--;
        }
        
        if(flag) {
            for(int i = 0; i < b; i++) {
                m[vb[i]]++;
            }
            n = n-a+b;
        }

    }

    cout << n << '\n';

    for(auto x: m) {
        for(int i = 0; i < x.second; i++) {
            cout << x.first << ' ';
        }
    }



}
// 알고리즘: 자료구조 (map), 구현 (쿼리 처리)
