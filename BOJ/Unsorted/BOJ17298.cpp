#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);


int N;
stack<pair<int,int>> s;
int ax;
int ans[1000001];
int arr[1000001];

int main() {
    fastio;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int bx;
        cin >> bx;
        arr[i] = bx;
    }

    s.push({arr[0],1});
    for(int i = 2; i <= N; i++) {
        if(s.top().first > arr[i-1]) {
            s.push({arr[i-1],i});
        }
        else {
            while(!s.empty() && s.top().first < arr[i-1] ) {
                ans[s.top().second-1] = arr[i-1];
                s.pop();
            }
            s.push({arr[i-1],i});
        }
    }

    while(!s.empty()) {
        ans[s.top().second-1] = -1; 
        s.pop();
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

}