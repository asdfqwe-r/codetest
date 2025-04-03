#include<bits/stdc++.h>
using namespace std;

/*
getchar의 활용도
주어지는 입력 문장 뒤에는 '\n'이 항상 존재함을 유념
scanf로 개행 안받아주면 뒤에서 받아버림
*/

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        string s;
        int arr[100001] = {0,};

        cin >> s;
        int n;
        scanf("%d\n",&n);

        getchar();
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d",&x);
            if(i != n-1) getchar();
            arr[i] = x;
        }
        getchar();
        getchar();

        int st(0),en(n-1);
        bool Rst = true;
        bool error = false;

        for(auto x : s) {
            if(x == 'R') Rst = !Rst;
            if(x == 'D') {
                if(en-st+1 <= 0) {
                    error = true;
                    break;
                }
                if(Rst) {
                    st++;
                }
                if(!Rst) {
                    en--;
                }
            }
        }

        if(error) {
            printf("error\n");
        }
        else {
            if(Rst) {
                printf("[");
                for(int i = st; i < en+1; i++) {
                    printf("%d",arr[i]);
                    if(i != en) printf(",");
                }
                printf("]\n");
            }
            else {
                printf("[");
                for(int i = en; i > st-1; i--) {
                    printf("%d",arr[i]);
                    if(i != st) printf(",");
                }
                printf("]\n");
            }
        }
        
    }

}
    
