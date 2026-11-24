#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

vector<vector<long long>> mul(vector<vector<long long>> A, vector<vector<long long>> B) {
    vector<vector<long long>> C(2, vector<long long>(2, 0));
    C[0][0] = ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
    C[0][1] = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
    C[1][0] = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
    C[1][1] = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
    return C;
}

vector<vector<ll>> f(vector<vector<ll>> A, ll n) {
    if(n == 1) return A;
    vector<vector<ll>> half = f(A, n/2);

    if(n%2 == 0) {
        return mul(half,half);
    }
    else {
        return mul(mul(half,half),A);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;

    vector<vector<ll>> A(2, vector<ll>(2));
    A[0][0] = 1, A[0][1] = 1, A[1][0] = 1, A[1][1] = 0;
    vector<vector<ll>> ans = f(A,n);
    
    cout << (ans[1][0])%MOD;
    return 0;
}