#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;
int cnt = 0;
int vst1[100];
int vst2[100];
int vst3[100];

void f(int x) {
    int xpos(x),ypos(1);
    if(x == n+1) {
        cnt++;
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(vst1[i]) continue;
        if(vst2[xpos-i+50]) continue;
        if(vst3[xpos+i]) continue;

        

        vst1[i] = 1;
        vst2[xpos-i+50] = 1;
        vst3[xpos+i] = 1;
        
        f(x+1);

        vst1[i] = 0;
        vst2[xpos-i+50] = 0;
        vst3[xpos+i] = 0;
        
    }

    return;
}


int main() {
    cin >> n;
    f(1);
    cout << cnt;


}