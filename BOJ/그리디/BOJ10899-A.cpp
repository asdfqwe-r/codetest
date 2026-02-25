#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    long long int p,n;
    cin >> p >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int tsum = 0;
    long long int pnum;
    for(int i = 0; i < n; i++) {
        tsum += v[i];
        if(tsum >= p) {
            tsum -= v[i];
            pnum = i;
            break;
        }
        pnum = i+1;
    }
    long long int ans = (p-1)*pnum;
    long long int sum = 0;
    for(int i = 0; i < pnum-1; i++) {
        sum += v[i];
        ans -= sum;
    }

    cout << pnum << ' ' << ans; 
    
}
// 알고리즘: 정렬, 그리디
