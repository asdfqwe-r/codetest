#include <bits/stdc++.h>
using namespace std;

int lc[(1<<10) + 1];
int rc[(1<<10) + 1];
vector<int> v;

void inorder(int cur) {
    if(lc[cur] != 0) inorder(lc[cur]);
    v.push_back(cur);
    if(rc[cur] != 0) inorder(rc[cur]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for(int i = 1; i < (1<<n-1); i++) {
        lc[i] = 2*i;
        rc[i] = 2*i+1; 
    }

    inorder(1);

    vector<pair<int,int>> ans;
    for(int i = 0; i < (1 << n) -1; i++) {
        int x;
        cin >> x;
        ans.push_back({v[i],x});
    }

    sort(ans.begin(), ans.end());

    int ex = 1;
    int cnt = 1;
    for(int i = 0; i < (1<<n) -1; i++) {
        cout << ans[i].second << ' ';
        if(cnt == ex) {
            ex *= 2;
            cout << '\n';
            cnt = 1;
        }
        else cnt++;
    }



    return 0;
}
// 알고리즘: 트리 (이진 트리), 중위순회 (Inorder Traversal), 레벨별 출력
