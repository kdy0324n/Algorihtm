#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int par[100010];
ll cost[100010];

int find(int n) {
	if (par[n] == 0)return n;
	int re = find(par[n]);
	par[n] = re;
	return re;
}

int Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return cost[u];
	par[u] = v;
	return cost[v] += cost[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		int t = Union(a, b);
		cout << t << '\n';
	}

	return 0;
}