#include<bits/stdc++.h>
using namespace std;

int CVal[11][5];

pair<int,int> ValSum(string s) {
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i <= 10; i++) {
    int cnt1 = 0;
    int cnt2 = 0;
        for(int j = 1; j <= 4; j++) {
            if(s[4*(i-1)+j-1] == '1') cnt1++;
            else if (s[4*(i-1)+j-1] == '2') cnt2++;
        }
    sum1 += CVal[i][cnt1];
    sum2 += CVal[i][cnt2];
    }

    return {sum1,sum2};
}

int main() {
    for(int i = 1; i < 11; i++) {
        for(int j = 1; j < 5; j++) {
            cin >> CVal[i][j];
        }
    }

    string MyC,TrdC,FnlC;
    cin >> MyC;
    cin >> TrdC;
    string DMB;
    cin >> DMB;

    for(int i = 0; i < 40; i++) {
        if(TrdC[i] == '0') {
            FnlC.push_back(MyC[i]);
        } 
        if(TrdC[i] == '1') {
            FnlC.push_back('1'); 
        }
        if(TrdC[i] == '2') {
            FnlC.push_back('2'); 
        }
    }

    int AG,BG,TrdAG,TrdBG,FnlAG(0),FnlBG(0);
    cin >> AG >> BG >> TrdAG >> TrdBG;
    FnlAG = AG + TrdBG - TrdAG;
    FnlBG = BG + TrdAG - TrdBG;
    
    int A,B;
    cin >> A >> B;

    int AVal0(0),AVal1(0),BVal0(0),BVal1(0);
    AVal0 += ValSum(MyC).first;
    AVal0 += AG*A/100;
    int cnt = 0;
    for(int i = 0; i < 40; i++) {
        if(DMB[i] == '1' && MyC[i] == '1') cnt++;
    }
    AVal0 -= cnt*B;

    BVal0 += ValSum(MyC).second;
    BVal0 += BG*A/100;
    cnt = 0;
    for(int i = 0; i < 40; i++) {
        if(DMB[i] == '1' && MyC[i] == '2') cnt++;
    }
    BVal0 -= cnt*B;

    AVal1 += ValSum(FnlC).first;
    AVal1 += FnlAG*A/100;
    cnt = 0;
    for(int i = 0; i < 40; i++) {
        if(DMB[i] == '1' && FnlC[i] == '1') cnt++;
    }
    AVal1 -= cnt*B;

    BVal1 += ValSum(FnlC).second;
    BVal1 += FnlBG*A/100;
    cnt = 0;
    for(int i = 0; i < 40; i++) {
        if(DMB[i] == '1' && FnlC[i] == '2') cnt++;
    }
    BVal1-= cnt*B;

    //cout << AVal1 << ' ' << BVal1 << '\n';

    string ans = (AVal0-BVal0) <= (AVal1-BVal1) ? "YES" : "NO"; 
    cout << ans;

}
// 알고리즘: 구현 (카드 게임 점수 계산), 비트마스크
