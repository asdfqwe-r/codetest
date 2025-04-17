#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int low = 0;
    int hi = 1000000001;

    if(n == 1) {
        cout << 0;
        return 0;
    }
    
    while(low < hi) {
        int mid = (low+hi)/2;
        int cnt = 0;

        if(abs(v[0]-v[1]) > mid) cnt++;
        for(int i = 1; i < n-1; i++) {
            if(abs(v[i]-v[i-1]) > mid || abs(v[i]-v[i+1]) > mid) {
                cnt++;
            }
        }
        if(abs(v[n-1]-v[n-2]) > mid) cnt++;

        if (cnt > k) {
            low = mid+1;
        }
        else if (cnt <= k) {
            hi = mid;
        }

        
    }

    cout << low;

}