#include<bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[100] = {0,};
        for(int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        auto MaxValP = max_element(arr,arr+n);
        int MaxVal = *MaxValP;

        cout << MaxVal*n << '\n';


    }
}