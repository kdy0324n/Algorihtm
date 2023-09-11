#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100010];

int n, m;
int chk[100010];
int cnt=1;
set<pair<int, int>>s;
int dfs(int cur, int par) {
	chk[cur] = cnt; cnt++;
	int ret = chk[cur];

	for (auto i : adj[cur]) {
		if (par == i)continue;
		if (chk[i]) {
			ret = min(ret, chk[i]);
			continue;
		}

		int tmp = dfs(i, cur);

		if (chk[cur] < tmp) {
			s.insert({ min(cur,i),max(cur,i) });
		}
		ret = min(ret, tmp);
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
		if (chk[i])continue;
		dfs(i, 0);
	}
	cout << s.size() << '\n';
	for (auto i : s) {
		cout << i.first << ' ' << i.second << '\n';
	}


	return 0;
}