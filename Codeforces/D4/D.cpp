#include<bits/stdc++.h>
using namespace std;

 int arr[200001] = {0,};
        int marr[200001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);
    
    int t;
    int n,m,h;
    cin >> t;
    while(t--) {
        cin >> n >> m >> h;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int CrashPos = 0;
        for(int i = 0; i < m; i++) {
            cin >> marr[i][0] >> marr[i][1];
            marr[i][0]--;
            arr[marr[i][0]] += marr[i][1];
            //cout << arr[p] << ' ';
            if(arr[marr[i][0]] > h) {
                for(int j = CrashPos; j <= i; j++) {
                    arr[marr[j][0]] -= marr[j][1];
                }
                CrashPos = i+1;
                continue;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

}