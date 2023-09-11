#include<bits/stdc++.h>
using namespace std;


vector<int>adj[10010];
int n, m;
int visited[10010];
int cnt = 1;
set<int>ans;

int dfs(int cur, bool isroot) {
	visited[cur] = cnt; cnt++;
	int inde = 0;
	int ret = visited[cur];

	for (auto i : adj[cur]) {
		if (visited[i]) {
			ret = min(ret, visited[i]);
			continue;
		}
		inde++;
		int n_ret = dfs(i, false);
		if (!isroot && n_ret>=visited[cur]) {
			ans.insert(cur);
		}
		ret = min(ret, n_ret);
	}
	if (isroot && inde >= 2) {
		ans.insert(cur);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		dfs(i, true);
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}

	return 0;
}