#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int n,m;
    cin >> n >> m;

    string chk = "I";
    string Input;

    cin >> Input;
    int ans = 0;

    for(int i = 0; i <= m-(n*2)-1; i++) {
        if(Input[i] == 'I') {
            int k = 0;
            while(Input[i+1] == 'O' && Input[i+2] == 'I') {
                k++;
                cout << k << ' ';
                if(k == n) {
                    //cout << i << ' ';
                    ans++;
                    k--;
                }
                i += 2;
            }
        }

    }

    cout << ans;



}