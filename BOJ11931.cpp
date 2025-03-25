#include<iostream>
#include<map>
using namespace std;

map<int,int> m;

int main() {
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < 1 << (n-1); i++) {
        int end = 1 << n;
        end--;
        m.insert({i,end-i});
    }

    int num = 1 << (n-k-1);
    int idx = 0;
    for(int i = 0; i < 1 << k; i++) {
        for(int j = 0; j < num; j++) {
            cout << idx << ' ' <<  m[idx] << ' ';
            idx++;
        }
        cout << '\n';
    }

}
