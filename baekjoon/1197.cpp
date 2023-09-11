/*#include<bits/stdc++.h>
using namespace std;

int n, m;
using pii = pair<int, int>;

vector<pii>adj[10010];

int dist[10010];
const int inf = 1e9;

int prim() {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	int ans = 0;
	vector<int>chk(n + 1);
	chk[1] = 1;
	for (auto i : adj[1])pq.emplace(i.second, i.first);
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		if (chk[t.second])continue;
		chk[t.second] = 1;
		ans += t.first;
		for (auto i : adj[t.second])pq.emplace(i.second, i.first);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	cout << prim();
	return 0;
}*/ //프림 알고리즘 풀이
#include<bits/stdc++.h>
using namespace std;

int n, m;

int par[10010];

int find(int u) {
	if (par[u] == 0)return u;
	int re = find(par[u]);
	par[u] = re;
	return re;
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return false;
	par[u] = v;
	return true;
}
using pii = pair<int, int>;

vector<pair<int, pii>>adj;

int kruskal() {
	int ans = 0;
	sort(adj.begin(), adj.end());
	for (auto i : adj) {
		int  u = i.second.first;
		int v = i.second.second;
		if (Union(u, v)) {
			ans += i.first;
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj.push_back({ c,{a,b} });
	}
	cout << kruskal();

	return 0;
}//크루스칼 알고리즘 풀이