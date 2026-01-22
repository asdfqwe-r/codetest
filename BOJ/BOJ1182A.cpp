#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n,s;
int arr[20];
int cnt = 0;

void f(int x, int sum) {
    if(x == n-1) {
        if(s == sum) cnt++;
        return;
    }

    f(x+1, sum+arr[x+1]);
    f(x+1, sum);
}


int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    f(0,arr[0]);
    f(0,0);

    if(s == 0) cnt--;

    cout << cnt;

}