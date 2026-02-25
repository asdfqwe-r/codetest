#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<int> v;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int MaxSpace = 0;
    int a,b;
    for(int i = 0; i < v.size()-1; i++) {
        if((v[i+1]-v[i])/2 > MaxSpace/2) {
            a = v[i];
            b = v[i+1];
            MaxSpace = b-a;
        }
    }

    if(MaxSpace < 1) {
        cout << "-1";
        return 0;
    }
    cout << (a+b)/2;

    
    return 0;
}
// 알고리즘: 정렬, 최솟값 탐색 (중앙값 삽입 위치)
