#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100010];
int n, r, q;


int chk[100010];
int v[100010];

int dfs(int cur) {
	int re = 1;
	for (auto i : adj[cur]) {
		if (chk[i])continue;
		chk[i] = 1;
		re += dfs(i);
	}
	return v[cur] = re;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	chk[r] = 1;
	dfs(r);
	while (q--) {
		int a; cin >> a;
		cout << v[a] << '\n';
	}
	return 0;
}