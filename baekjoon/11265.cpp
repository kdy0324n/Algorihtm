#include<bits/stdc++.h>
using namespace std;

int n, m;

int arr[510][510];


void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
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
			cin >> arr[i][j];
		}
	}
	floyd();
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] <= c)cout << "Enjoy other party";
		else cout << "Stay here";
		cout << '\n';
	}
	return 0;
}