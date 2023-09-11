#include<bits/stdc++.h>
using namespace std;

int n;
int par[1010];
int chk[1010];

int dfs(int cur, int sum) {
	if (chk[cur])return 0;
	chk[cur] = 1;
	int re= dfs(par[cur],sum+1)+1;
	chk[cur] = 0;
	return re;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
	}
	int ans = 0; int idx;
	for (int i = 1; i <= n; i++) {
		chk[i] = 1;
		int val = dfs(par[i], 1);
		chk[i] = 0;
		if (val > ans) {
			ans = val;
			idx = i;
		}
		else if (val == ans) {
			idx = min(idx, i);
		}
	}
	cout << idx;

	return 0;
}