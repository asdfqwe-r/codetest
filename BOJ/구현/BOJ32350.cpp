#include<bits/stdc++.h>
using namespace std;

int n,d,p;

int Ovr(int d, int p) {
    float ex;
    ex = (float)d*p/100;
    ex = trunc(ex);
    return (int)ex;
}

int main() {
    cin >> n >> d >> p;

    int arr[101] = {0,};

    for(int i = 0; i < n; i++) cin >> arr[i];

    int idx = 0;
    int cnt = 0;
    while(arr[n-1] > 0) {
        if(arr[idx] > d) {
            arr[idx] -= d;
        }
        else if (arr[idx] == d){
            arr[idx] -= d;
            idx++;
        }
        else {
            int temp = d-arr[idx];
            arr[idx] = 0;
            temp = Ovr(temp,p);
            idx++;
            if(arr[idx] <= temp) {
                arr[idx] = 0;
                idx++;
            }
            else {
                arr[idx] -= temp;
            }
        }

        

        cnt++;
    }

    cout << cnt;




}
// 알고리즘: 구현 (시뮬레이션)
