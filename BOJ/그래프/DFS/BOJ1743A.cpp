#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>, int> piii;

int N, M, K;

bool vis[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;
int map[101][101];

int DFS(int x, int y) {
	int cnt = 1; 
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
			if (!vis[nx][ny] && map[nx][ny] != 0) {
				vis[nx][ny] = true;
				cnt += DFS(nx, ny);
			}
		}
	}
	return cnt;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != 0 && !vis[i][j]) {
				vis[i][j] = true;
				ans = max(ans, DFS(i, j));
			}
		}
	}


	cout << ans << "\n";

	return 0;
}
// 알고리즘: DFS, 연결 성분 (다른 구현)
