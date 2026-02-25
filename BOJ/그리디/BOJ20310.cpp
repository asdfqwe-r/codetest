#include <bits/stdc++.h>
using namespace std;

int main() {
    int num0 = 0;
    int num1 = 0;

    string s;
    int arr[1001];
    cin >> s;

    int idx = 0;
    for(auto x : s) {
        if(x == '0') { 
        arr[idx] = 0;
        num0++;
        }
        if(x == '1' ) { 
        arr[idx] = 1;
        num1++;
        }

        idx++;
    }
    idx--;

    num0 /= 2;
    num1 /= 2;

    for(int i = 0; i <= idx; i++) {
        if(num1 == 0) break;
        if(arr[i] == 1) {
            arr[i] = -1;
            num1--;
        }
    }

    for(int i = idx; i >= 0; i--) {
        if(num0 == 0) break;
        if(arr[i] == 0) {
            arr[i] = -1;
            num0--;
        }
    }

    for(int i = 0; i <= idx; i++) {
        if(arr[i] == -1) continue;
        cout << arr[i];
    }
    
    
    
}
// 알고리즘: 그리디 (0과 1 재배치)
