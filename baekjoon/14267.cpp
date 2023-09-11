#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int>adj[100010];
int cost[100010];
int chk[100010];
void dfs(int cur) {
	for (auto i : adj[cur]) {
		if (chk[i])continue;
		cost[i] += cost[cur];
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == -1)continue;
		adj[a].push_back(i);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cost[a] += b;
	}
	chk[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; i++)cout << cost[i] << ' ';
	return 0;
}