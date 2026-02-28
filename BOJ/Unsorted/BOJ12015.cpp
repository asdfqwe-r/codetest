#include <bits/stdc++.h>
using namespace std;

vector<int> low;
int idx[1000001];

vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for(int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back(x);
        int pos = lower_bound(low.begin(), low.end(), x) - low.begin();
        if(pos == low.size()) {
            low.push_back(x);
        }
        else {
            low[pos] = x;
        }
        idx[i] = pos;
    }
}

