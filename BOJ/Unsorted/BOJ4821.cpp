#include <bits/stdc++.h>
#include <cstddef>
#include <sstream>
using namespace std;

int arr[1001];

int main() {
    int N;
    while(cin >> N && N != 0) {
        memset(arr,0,sizeof(arr));

        string s;
        cin >> s;

        stringstream ss(s);
        string idx;

        while(getline(ss,idx,',')) {
            size_t pos = idx.find('-');
            if(pos != string::npos) {
                int low = stoi(idx.substr(0,pos));
                int high = stoi(idx.substr(pos+1));
                for(int i = low; i <= high; i++) {
                    arr[i]++;
                }
            }
            else {
                int x = stoi(idx);
                arr[x]++;
            }
        }

        int ans = 0;
        for(int i = 1; i <= N; i++) {
            if(arr[i] > 0) ans++;
        }

        cout << ans << '\n';
    }
}