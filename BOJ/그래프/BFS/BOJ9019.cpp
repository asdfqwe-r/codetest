#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int D(int n) {
    int ret = (2*n)%10000;
    return ret;
}

int S(int n) {
    int ret = n == 0? 9999 : n-1;
    return ret;
}

int L(int n) {
    int temp = n%1000;
    int ret = temp*10 + n/1000;
    return ret;
}

int R(int n) {
    int temp = n%10;
    int ret = temp * 1000 + n/10;
    return ret;
}

int main() {
    int t;

    cin >> t;

    while(t--) {
        int a,b;
        cin >> a >> b;

        queue<int> q;
        queue<string> sq;
        int vst[10000] = {0,};

        q.push(a);
        sq.push("");

        while(!q.empty()) {
            int temp = q.front();
            string tempstr = sq.front();

            if(temp == b) {
                cout << tempstr << '\n';
                break;
            }

            q.pop();
            sq.pop();

            for(int i = 0; i < 4; i++) {
                int ntemp;
                string ntempstr;
                if(i == 0) {
                    ntemp = D(temp);
                    ntempstr = tempstr + "D";
                }if(i == 1) {
                    ntemp = S(temp);
                    ntempstr = tempstr + "S";
                }
                if(i == 2) {
                    ntemp = L(temp);
                    ntempstr = tempstr + "L";
                }
                if(i == 3) {
                    ntemp = R(temp);
                    ntempstr = tempstr + "R";
                }
                
                if(vst[ntemp] == 0) {
                    q.push(ntemp);
                    sq.push(ntempstr);
                    vst[ntemp] = 1;
                }
            
            }


        }
    }
}
// 알고리즘: BFS, DSLR 상태 탐색, 문자열 경로 추적
