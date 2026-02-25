#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n,m;
int arr[110001];
int cnt[110001];
int Ai[110001],Bi[110001],Ci[110001];

//누적합 응용!

ll PComp(int a, int b) {
    ll P1 = (long long)Ai[a]*b;
    ll P2 = (long long)Bi[a]*b + (long long)Ci[a];

    return P1 > P2 ? P2 : P1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < m; i++) {
        int St = arr[i] > arr[i+1] ? arr[i+1] : arr[i];
        int En = arr[i] < arr[i+1] ? arr[i+1] : arr[i];
        
        cnt[St]++;
        cnt[En]--;
    }

    for(int i = 1; i < n; i++) {
        cnt[i] = cnt[i-1] + cnt[i];
    }

    for(int i = 1; i < n; i++) {
        cin >> Ai[i] >> Bi[i] >> Ci[i];
    }

    ll sum = 0;
    for(int i = 1; i < n; i++) {
        sum += PComp(i,cnt[i]);
    }

    cout << sum;
}
// 알고리즘: 누적합 (1D Prefix Sum), 차분 배열
