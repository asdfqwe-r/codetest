#include <bits/stdc++.h>
using namespace std;

vector<int> Nv;
vector<int> Or;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin >> N >> M;
    Nv.resize(N);
    Or.resize(M);

    for(auto &x: Nv) cin >> x;
    for(auto &x: Or) cin >> x;

    sort(Nv.begin(),Nv.end());
    sort(Or.begin(), Or.end());

    int ans1 = 1, ans2 = 1;
    int NvCool = Nv[0] + 100, OrCool = Or[0] + 360;

    for(auto x : Nv) {
        if(x >= NvCool) {
            ans1++;
            NvCool = x+100;
        }
    }

    for(auto x : Or) {
        if(x >= OrCool) {
            ans2++;
            OrCool = x+360;
        }
    }

    cout << ans1 << ' ' << ans2;
    return 0;
}