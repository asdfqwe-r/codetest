#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int al[5001][2];
char pre[5001][5001];


int main () {
    fill(&dp[0][0],&dp[5001][5001],-1);
    
    int N,A,L;
    cin >> N >> A >> L;

    for(int i = 1; i <= N; i++) {
        scanf("%d %d",&al[i][0],&al[i][1]);
    }

    dp[0][L] = A;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= L; j++) {
            //A
            if(dp[i-1][j] > al[i][0]) {
                if(dp[i-1][j]-al[i][0] > dp[i][j]) pre[i][j] = 'A';
                dp[i][j] = max(dp[i][j],dp[i-1][j]-al[i][0]);
            }
            //L
            if(j > al[i][1] ) {
                if(dp[i-1][j] > dp[i][j-al[i][1]]) pre[i][j-al[i][1]] = 'L';
                dp[i][j-al[i][1]] = max(dp[i][j-al[i][1]],dp[i-1][j]);
            }
        }   
    }


    int ex = 0;
    //CHECK
    for(int i = 1; i <= L; i++) {
        if(dp[N][i] >= 0) {
            ex = i;
            break;
        }
    }
    if(ex == 0) {
        cout << "NO";
        return 0;
    }
    int nowLife = ex;
    int nowAura = dp[N][ex];
    int ans[5001];

    for(int i = N; i > 0; i--) {
        ans[i-1] = pre[i][nowLife];
        cout << i << ' ' << nowLife << '\n';
        if(pre[i][nowLife] = 'A') {
        }
        if(pre[i][nowLife] = 'L') {
            nowLife += al[i][1];
        }
    }

    for(int i = N-1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}
// 알고리즘: DP, 역추적 (미완성)
