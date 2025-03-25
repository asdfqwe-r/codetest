#include<iostream>
using namespace std;

int arr[4];
int ans[10001];
int main() {
    int t;
    cin >> t;
    
    for(int ix = 0; ix < t; ix++) {
        for(int i = 0; i < 4; i++) {
            cin >> arr[i];
        }
        
        int flag = 0;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(arr[i] != arr[j]) {
                    flag = 1;
                    break;
                } 
            }
            if(flag == 1) break;
        }

        ans[ix] = flag;
    }

    for(int i = 0; i < t; i++) {
        if(ans[i] == 1) cout << "NO\n";
        else cout << "YES\n";
    }

}