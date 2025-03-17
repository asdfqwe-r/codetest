#include <stdio.h>
#include <iostream>
using namespace std;

char arr[601][601];
int vst[601][601];
int ix = 0;
int iy = 0;
int pcnt = 0;
int n,m;
void bfs(int xpos, int ypos) {
    if(xpos >= n || xpos < 0) return;
    if(ypos >= m || ypos < 0) return;
    vst[xpos][ypos] = 1;
    if(arr[xpos][ypos] == 'P') pcnt++;

    if(arr[xpos+1][ypos] != 'X' && vst[xpos+1][ypos] == 0) {
        bfs(xpos+1,ypos);
    }
    if(arr[xpos-1][ypos] != 'X' && vst[xpos-1][ypos] == 0) {
        bfs(xpos-1,ypos);
    }
    if(arr[xpos][ypos+1] != 'X' && vst[xpos][ypos+1] == 0) {
        bfs(xpos,ypos+1);
    }
    if(arr[xpos][ypos-1] != 'X' && vst[xpos][ypos-1] == 0) {
        bfs(xpos,ypos-1);
    }
    return;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if(x == 'I') {
                ix = i;
                iy = j;
            }
            arr[i][j] = x;
        }
    }

    bfs(ix,iy);

    if(pcnt == 0) cout << "TT";
    else cout << pcnt;



}