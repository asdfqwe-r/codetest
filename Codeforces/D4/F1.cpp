#include<bits/stdc++.h>
using namespace std;

int Xor[300000];
int arr[300000];

int get_xor(int L, int R) {
    if (L == 0) return Xor[R];
    return Xor[R] ^ Xor[L - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--) {
        int n, q;
        vector<int> v;
        cin >> n >> q;
        
        for(int i = 0; i < (1 << n); i++) {
            cin >> arr[i];
            if(i == 0) {
                Xor[0] = arr[0];
            }
            else {
                Xor[i] = Xor[i-1] ^ arr[i]; 
            }
        }

        while(q--) {
            int b, c;
            cin >> b >> c;
            b--;
            
            int NowVal = c;
            int ans = 0;

            for(int i = 0; i < n; i++) {
                int win = 0; 
                
                int st = b & ~((1 << (i + 1)) - 1);
                int mid = st + (1 << i);
                
                int cmp;

                if(b < mid) {
                    cmp = get_xor(mid, mid + (1 << i) - 1); 
                    if(NowVal >= cmp) win = 1;
                }
                else {
                    cmp = get_xor(st, mid - 1);
                    if(NowVal > cmp) win = 1;
                }
                win = !win; 
                v.push_back(win);
                NowVal = NowVal ^cmp;
            }

            

            int pow2 = 1;
            
            for(int i = 0; i < v.size(); i++) {
                if(v[i] == 1) ans += pow2; 
                pow2 *= 2;
            }

            cout << ans << '\n';
            v.clear(); 
        }
    }
    return 0;
}