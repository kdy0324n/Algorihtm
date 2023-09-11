#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>>adj[10010];

int idx, ans;
int chk[10010];

void dfs(int cur,int sum) {
	if (sum > ans) {
		ans = sum;
		idx = cur;
	}
	for (auto i : adj[cur]) {
		if (chk[i.first])continue;
		chk[i.first] = 1;
		dfs(i.first,sum+i.second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	chk[1] = 1;
	dfs(1, 0);

	int u = idx;
	ans = 0;
	memset(chk, 0, sizeof(chk));
	chk[u] = 1;
	dfs(u, 0);
	cout << ans;

	return 0;
}
