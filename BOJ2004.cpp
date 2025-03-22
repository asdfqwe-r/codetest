#include<iostream>
using namespace std;

long long int cnt(int n, int q) {
    if(n < q) return 0;
    return cnt(n/q,q)+ (n/q);
}


int main() {
    long long num5;
    long long num2;

    int n,m;
    cin >> n >> m;

    num5 = cnt(n,5)-cnt(m,5)-cnt(n-m,5);
    num2 = cnt(n,2)-cnt(m,2)-cnt(n-m,2);

    int ans = num5 > num2 ? num2:num5;
    cout << ans;

}