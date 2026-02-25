#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;
int cnt = 0;
int arr[10];
void f(int x) {
    if(x == n+1) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += arr[i];
        }
        if(sum%3 == 0&&arr[1] != 0) {
            cnt++;
        }

        return;
    }

    for(int i = 0; i < 3; i++) {
        arr[x] = i;
        f(x+1);
        arr[x] = 0;
    }

}


int main() {
    cin >> n;
    f(1);
    cout << cnt;

}
// 알고리즘: 백트래킹, 완전 탐색
