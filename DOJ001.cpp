#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack<int> s;

int main() {
    int N;
    cin >> N;
    int cnt1(0), cnt2(0);

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if(x == 1) cnt1++;
        else cnt2++;
    }

    if(cnt2 > cnt1) cout << "No";
    else if((cnt1-cnt2)%3 == 0) cout << "Yes";
    else cout << "No";

}