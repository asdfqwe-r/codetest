#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[400001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int st = 0;
    int end = 0;
    int ans = 0;
    int numstr[10] = {0,};
    numstr[arr[0]]++;
    while(end < n) {
        
        int numcnt = 0;

        for(int i = 0; i < 10; i++) {
            numcnt += bool(numstr[i]);
        }
        
        if(numcnt < 3) {
            ans = ans > end-st+1 ? ans:end-st+1;
            end++;
            numstr[arr[end]]++;
        }
        else {
        st++;
        numstr[arr[st-1]]--;
        }
    }

    cout << ans;
}