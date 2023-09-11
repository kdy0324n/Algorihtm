#include<bits/stdc++.h>
using namespace std;

vector<int>ans, v;
vector<int>adj[100010];
int n;
int order[100010];
int chk[100010];
bool b = false;
void dfs(int idx) {
	for (auto i : adj[idx]) {
		if (chk[i])continue;
		chk[i] = 1;
		v.push_back(i);
		dfs(i);
	}
}

bool cmp(int l, int r) {
	return order[l] < order[r];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		ans.push_back(a);
		order[a] = i;
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	chk[1] = 1;
	v.push_back(1);
	dfs(1);
	if (ans == v)cout << 1;
	else cout << 0;

	return 0;
}