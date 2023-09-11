#include<bits/stdc++.h>
using namespace std;

int n, m;
int par[100010];
int Size[100010];

int Find(int u) {
	if (par[u] == 0)return u;
	int re = Find(par[u]);
	par[u] = re;
	return re;
}

void Union(int u, int v,int type) {
	u = Find(u);
	v = Find(v);
	if (u == v)return;
	if (type == 1) {
		par[u] = v;
		Size[v] += Size[u];
	}
	else {
		if (Size[u] == Size[v]) {
			par[u] = par[v] = -1;
			return;
		}
		if (Size[u] > Size[v])swap(u, v);
		par[u] = v;
		Size[v] -= Size[u];
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> Size[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Union(b, c, a);
	}
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0)v.push_back(Size[i]);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto i : v) {
		cout << i << ' ';
	}

	return 0;
}