#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int ans;
int t;
int n, m;
int arr[21][21];
int d[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool Find(int type,int y, int x) {
	for (int i = 0; i < 3; i++) {
		int ny = y + d[type][i][0];
		int nx = x + d[type][i][1];
		if (ny<1 || ny>n || nx<1 || nx>m)return false;
		if (arr[ny][nx])return false;
	}
	return true;
}

void update(int type, int y, int x, int val) {
	for (int i = 0; i < 3; i++) {
		int ny = y + d[type][i][0];
		int nx = x + d[type][i][1];
		arr[ny][nx] = val;
	}
}
void dfs() {
	bool a = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j])continue;
			for (int k = 0; k < 4; k++) {
				if (Find(k, i, j)) {
					update(k, i, j, 1);
					dfs();
					update(k, i, j, 0);
				}				
			}
			a = false;
			break;
		}
		if (!a)break;
	}
	if (a)ans++;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		ans=0;
		cin >> n >> m;
		for (int i = 1; i<= n; i++) {
			string str; cin >> str;
			for (int j = 1; j <= m; j++) {
				if (str[j - 1] == '#')arr[i][j] = 1;
				else arr[i][j] = 0;
			}
		}
		dfs();
		cout << ans << '\n';
	}

	return 0;
}