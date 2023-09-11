#include<iostream>
#include<string.h>
using namespace std;

int arr[110][110];
int dp[110][110];

int n;
void solve(int y, int x) {
	if (dp[y][x])return;
	dp[y][x] = 1;
	
	int ny = y + arr[y][x];
	int nx = x + arr[y][x];
	if (ny <= n)solve(ny, x);

	if (nx <= n)solve(y, nx);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		solve(1, 1);
		if (dp[n][n])cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	

	return 0;
}