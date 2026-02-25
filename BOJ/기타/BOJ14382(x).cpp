#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int t;
    cin >> t;

    while(t--) {
        int idx = 1;
        int n;
        cin >> n;

        int arr[10] = {0,};
        for(int i = 1; i < 11; i++) {
            int chk = i*n;
            while(chk) {
                arr[chk%10]++;
                chk /= 10;
            }
        }

        bool ans = true;
        for(int i = 0; i < 10; i++) {
            if(!arr[i]) ans = false;
        }

        if(ans) {
            
        }

    }
}
// 알고리즘: 미완성
