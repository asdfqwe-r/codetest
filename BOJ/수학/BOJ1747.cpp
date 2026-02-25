#include<bits/stdc++.h>
using namespace std;

bool isPal(int n) {
    vector<int> v1;
    while(n) {
        v1.push_back(n%10);
        n /= 10;
    }

    bool flag = true;
    for(int i = 0; i < (v1.size()+1)/2; i++) {
        if(v1[v1.size()-1-i] != v1[i]) {
            flag = false;
        }
    }
    return flag;
}

bool isP(int n) {
    bool flag = true;
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {

    int n;
    cin >> n;
    while(1) {
        if(!isPal(n)) {
            n++;
            continue;
        }
        if(!isP(n)) {
            n++;
            continue;
        }

        break;
    }

    cout << n;


}
// 알고리즘: 소수 판별 (Primality Test), 팰린드롬 판별
