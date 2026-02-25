#include <bits/stdc++.h>
using namespace std;

int M = 1000000;

int solve(int n) {
    int sum = 0;
    sum += ((long long)n*(long long)(n-1))/2 % M;
    sum++;
    sum -= n;

    for(int i = 2; i <= n; i++) {
        sum -= n%i;
        sum %= M;
    }
    if(sum < 0) sum += M;
    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);

}
// 알고리즘: 수학 (나머지 합, 포함-배제 원리)
