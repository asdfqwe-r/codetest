#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        int maxc = k%n == 0 ? k/n : k/n+1;
        if(maxc == m) cout << m << '\n';
        else if(maxc%(m-maxc+1) == 0) cout << maxc/(m-maxc+1) << '\n';
        else cout << (maxc/(m-maxc+1))+1 << '\n';
    }

}