#include<bits/stdc++.h>
using namespace std;

int arr[600][600];
int n, m;
int dy[19][4] = { {0,0,0,0},{0,1,2,3},{0,0,1,1},
{0,0,-1,-2},{0,0,-1,-2},{0,0,1,2},{0,0,1,2},
{0,0,0,-1},{0,0,0,-1},{0,0,0,1},{0,0,0,1},
{0,1,1,2},{0,1,1,2},{0,0,-1,-1},{0,0,1,1},
{0,0,-1,1},{0,0,-1,1},{0,0,-1,0},{0,0,1,0}
				};
int dx[19][4] = { {0,1,2,3},{0,0,0,0},{0,1,0,1},
{0,1,1,1},{0,-1,-1,-1},{0,1,1,1},{0,-1,-1,-1},
{0,1,2,2},{0,-1,-2,-2},{0,1,2,2},{0,-1,-2,-2},
{0,0,1,1},{0,0,-1,-1},{0,1,1,2},{0,1,1,2},
{0,1,1,1},{0,-1,-1,-1},{0,1,1,2},{0,1,1,2}
};
int fuc(int y, int x) {
	int res = 0;
	for (int i = 0; i < 19; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[i][j];
			int nx = x + dx[i][j];
			tmp += arr[ny][nx];
		}
		res = max(res, tmp);
	}
	return res;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 4; i < n+4; i++) {
		for (int j = 4; j < m+4; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 4; i < 4 + n; i++) {
		for (int j = 4; j < 4 + m; j++) {
			ans = max(ans, fuc(i, j));
		}
	}
	cout << ans;

	return 0;
}