#include<bits/stdc++.h>
using namespace std;


int n;
int par[300010];

int Find(int u) {
	if (par[u] == 0)return u;
	int re = Find(par[u]);
	par[u] = re;
	return re;
}

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v)return;
	par[u] = v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 2; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0)cout << i << ' ';
	}

	return 0;
}