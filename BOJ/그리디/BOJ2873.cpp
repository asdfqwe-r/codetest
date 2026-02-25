#include<bits/stdc++.h>
using namespace std;
#define ll long long

int arr[1001][1001];


int main() {
    int r,c;
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    if(r%2 == 1) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(i == r-1) {
                    if(j == c-1) {
                        break;
                    }
                    else cout << 'R';
                }
                else if(i%2 == 0) {
                    if(j == c-1) cout << 'D';
                    else cout << 'R';
                }
                else {
                    if(j == c-1) cout << 'D';
                    else cout << 'L';
                }
            }
        }
        return 0;
    }
    else if(c%2 == 1) {
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                if(i == c-1) {
                    if(j == r-1) {
                        break;
                    }
                    else cout << 'D';
                }
                else if(i%2 == 0) {
                    if(j == r-1) cout << 'R';
                    else cout << 'D';
                }
                else {
                    if(j == r-1) cout << 'R';
                    else cout << 'U';
                }
            }
        }
        return 0;
    }

    else {
        pair<int,int> MinPos = {-1,-1};
        int MinVal = 1001;
        //Minfind
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(i == 0 && j == 0) continue;
                if(arr[i][j] < MinVal && (i+j)%2 == 1) {
                    MinVal = MinVal > arr[i][j] ? arr[i][j] : MinVal;
                    MinPos = {i,j};
                }
            }
        }
        int SnakeSt = MinPos.first - (MinPos.first%2);
        int xpos = 0;
        int ypos = 0;
        while(1) {
            if(xpos == SnakeSt || xpos == SnakeSt+1) {
                for(int i = 0; i < MinPos.second; i++) {
                    if(i%2 == 0) cout << "DR";
                    else cout << "UR";
                }
                for(int i = MinPos.second; i < c-1; i++) {
                    if(i%2 == 0) cout << "RD";
                    else cout << "RU";
                }

                xpos = SnakeSt+2;
                ypos = c-1;

                break;
            }
            else if(xpos%2 == 0) {
                if(ypos == c-1) {
                    cout << 'D';
                    xpos++;
                }
                else {
                    cout << 'R';
                    ypos++;
                }
            }
            else {
                if(ypos == 0) {
                    cout << 'D';
                    xpos++;
                }
                else {
                    cout << 'L';
                    ypos--;
                }
            }

        }

        if(xpos > r-1) return 0;

        cout << 'D';

        while(1) {
            if(xpos == r-1 && ypos == c-1) break;
            
            if(xpos%2 == 1) {
                if(ypos == c-1) {
                    cout << 'D';
                    xpos++;
                }
                else {
                    cout << 'R';
                    ypos++;
                }
            }
            else {
                if(ypos == 0) {
                    cout << 'D';
                    xpos++;
                }
                else {
                    cout << 'L';
                    ypos--;
                }
            }
        }
        



    }


}
// 알고리즘: 그리디 (격자 경로, 홀짝 처리)
