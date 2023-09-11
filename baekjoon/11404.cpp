#include<bits/stdc++.h>
using namespace std;


int n, m;
int arr[110][110];
int inf = 1e9;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i=1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			arr[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b],c);
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == inf)cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}