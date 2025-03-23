#include<iostream>
using namespace std;


int arr[201][201];
int n,m;

void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i!=j) arr[i][j] = 1<<20; 
        }
    }
}

int main() {
    cin >> n >> m;

    init();

    for(int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    //Floyd-Warshall
    for(int m = 1; m <= n; m++) {
        for(int s = 1; s <= n; s++) {
            for(int e = 1; e <= n; e++) {
                if(arr[s][e] > arr[s][m] + arr[m][e]) {
                    arr[s][e] = arr[s][m] + arr[m][e];
                }
            }
        }
    }


    int k;
    int ci[301];
    int ans[301];
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> ci[i];
    }
    

    for(int i = 1; i <= n; i++) {
        int ex = -1;
        for(int j = 0; j < k; j++) {
            ex = arr[ci[j]][i]+arr[i][ci[j]] > ex ? arr[ci[j]][i]+arr[i][ci[j]] : ex; 
        }
        ans[i] = ex;
    }

    int mini = 1 << 20;
    for(int i = 1; i <= n; i++) {
        mini = mini < ans[i] ? mini : ans[i];
    }
/*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
*/
    for(int i = 1; i <= n; i++) {
        if(ans[i] == mini) cout << i << ' ';
    }


    
    

}