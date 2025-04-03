#include<bits/stdc++.h>
using namespace std;

int arr[101][101][101];
int chk[101][101][101];

struct {
    int x;
    int y;
    int z;
}pos;

int main() {
    
    queue<int> cnt;
    queue<pos> q;
    
    int n,m,h;
    cin >> n >> m >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                cin >> arr[k][j][i];
                if(arr[k][j][i] == 1) { 
                    chk[k][j][i] = 1;
                    st temp;
                    temp.x = k, temp.y = j, temp.z = i;
                    q.push(temp);
                    cnt.push(x);
                }
            }
        }
    }

    

    while(!q.empty())


}