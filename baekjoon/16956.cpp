#include<bits/stdc++.h>
using namespace std;

int n, m;

char arr[510][510];

vector<pair<int, int>>v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
			if (arr[i][j] == 'W') {
				v.emplace_back(i, j);
			}
			else if(arr[i][j]=='.'){
				arr[i][j] = 'D';
			}
		}
	}
	bool b=true;
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };
 	for (auto i : v) {
		for (int j = 0; j < 4; j++) {
			int ny = i.first + dy[j];
			int nx = i.second + dx[j];
			if (arr[ny][nx] == 'S') {
				b = false;
				break;
			}
		}
		if (b == false)break;
	}
	if (b == false) {
		cout << 0;
	}
	else {
		cout << 1 << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)cout << arr[i][j];
			cout << '\n';
		}
	}

	return 0;
}