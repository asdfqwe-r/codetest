#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        double B;
        cin >> n >> B;
        double r[100001];

        int x,y;
        cin >> x >> y;
        for(int i = 0; i < n; i++) {
            int xi,yi,si;
            cin >> xi >> yi >> si;
            double diff = (double)((x-xi)*(x-xi) + (y-yi)*(y-yi));
            r[i] = (double)(si)/diff;
            
        }

        double sum = 0;
        for(int i = 0; i < n; i++) {
            sum += r[i];
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(r[i] > 6*(B+sum-r[i])) ans = i;
        }  

        if(ans == -1) cout << "NOISE" << '\n';
        else cout << ans+1 << '\n';

        
    }
}