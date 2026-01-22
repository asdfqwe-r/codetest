#include<bits/stdc++.h>
using namespace std;

int arr[100];

int main() {
    int n,m;
    cin >> n >> m;

    memset(arr,1,sizeof(arr));
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        for(int j = x; j< y; j++) {
            arr[j] = 0;
          
        }
    }

    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i]) cnt++;
    }

    cout << cnt+1;
    

}