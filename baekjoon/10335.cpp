#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using tiiii = tuple<int, int, int, int>;

vector<tiiii>adj;
int n, m;
int par[510];
int w[50010];
vector<int>Index;
int Find(int u) {
	if (par[u] == 0)return u;
	int ret = Find(par[u]);
	par[u] = ret;
	return ret;
}
bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v)return false;
	par[u] = v; return true;
}
int kruscal() {
	int sum = 0;
	for (auto i : adj) {
		int u = get<0>(i);
		int v = get<1>(i);
		int j = get<2>(i);
		int idx = get<3>(i);
		if (Union(u, v)) {
			sum += j;
			Index.push_back(idx);
		}
	}
	return sum;
}
int kruscal1(int lim_idx) {
	int sum = 0;
	for (auto i : adj) {
		int u = get<0>(i);
		int v = get<1>(i);
		int j = get<2>(i);
		int idx = get<3>(i);
		if (idx == lim_idx)continue;
		if (Union(u, v)) {
			sum += j;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj.emplace_back(a, b, c, i);
		w[i] = c;
	}
	sort(adj.begin(), adj.end(), [](tiiii l, tiiii r) {
		return get<2>(l) < get<2>(r);
		});
	int ans = 0, cnt = 0;
	int mst = kruscal();

	for (int i = 0; i < Index.size(); i++) {
		int id = Index[i];
		memset(par, 0, sizeof(par));
		int tmp = kruscal1(id);
		if (tmp != mst) {
			cnt++;
			ans += w[id];
		}
	}
	cout << cnt << ' ' << ans;
	return 0;
}