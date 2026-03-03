#include <bits/stdc++.h>
using namespace std;

const int ARR_MAX = 1000001;
const int I_MAX = 0x3ffffff;

int DP[ARR_MAX];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for(int i = 0; i < ARR_MAX; i++) {
        DP[i] = -I_MAX; 
    }

    for(int i = 0,x; i < N; i++) {
        cin >> x;
        DP[x] = 0;
        v.push_back(x);
    }

    for(int i = 1; i < ARR_MAX; i++) {
        if(DP[i] < -100000) continue;
        for(int j = i*2; j < ARR_MAX; j += i) {
            if(DP[j] < -100000) continue;
            DP[i]++;
            DP[j]--;
        }
    }

    for(auto x : v) {
        cout << DP[x] << ' ';
    }
    
    return 0;
}