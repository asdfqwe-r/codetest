#include<iostream>
using namespace std;

int main() {
    int n,k;
    cin >>n >> k;
    int endtime;
    bool flag = true;
    int st[3];
    int en[3];
    for(int i = 0; i < 3; i++) {
        cin >> st[i] >> en[i];
    }

    endtime = (en[0] + k);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if (i == 0 && j == 0) continue;
            
            if(endtime < st[j]+i*1440) flag = false;
            else if(endtime <= en[j]+i*1440) endtime += k;
            else if(endtime >= en[j]+i*1440) endtime = en[j]+i*1440 + k;

            if(flag == false) break;

        }    
        if(flag == false) break;
    }

    if(flag == true) cout << "YES";
    else cout << "NO";

}
// 알고리즘: 구현 (시간표 시뮬레이션)
