#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[1010][1010];
int chk[1010][1010][2];
struct dd {
	int y, x, time,type;
};

queue<dd>q;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int bfs() {
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.y == n && t.x == m)return t.time;

		for (int i = 0; i < 4; i++) {
			int ny = t.y + dy[i];
			int nx = t.x + dx[i];
			int n_time = t.time + 1;
			int n_type = t.type;

			if (ny<1 || ny>n || nx<1 || nx>m)continue;
			if (chk[ny][nx][n_type])continue;

			if (arr[ny][nx] == 0) {
				chk[ny][nx][n_type] = 1;
				q.push({ ny,nx,n_time,n_type });
			}
			if (arr[ny][nx] == 1&&n_type==0) {
				n_type = 1;
				chk[ny][nx][n_type] = 1;
				q.push({ ny,nx,n_time,n_type });
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1] - 48;
		}
	}
	q.push({ 1,1,1,0 });
	chk[1][1][0] = 1;
	ans = bfs();
	if (ans == -1)cout << -1;
	else cout << ans;
	
	return 0;
}