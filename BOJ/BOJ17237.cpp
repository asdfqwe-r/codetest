#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int arr[21];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }


    int flag = 0;
    //if 0 - und, 1- B, 2 - A
    for(int i = 20; i > 0; i--) {
        arr[i-1] += arr[i]/2;
    }
    
    //cout << arr[0] << ' ';

    if(arr[0] >= 1) {
        flag = 2;
        
    }
    else flag = 1;

    if(flag == 1) cout << 'B';
    else if(flag == 2) cout << 'A';


}