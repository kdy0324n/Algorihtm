#include<bits/stdc++.h>
using namespace std;

int n;
int m;
using pii = pair<int, int>;
using piii = pair<pii, int>;//
vector<pii>adj[1010];
int dist[1010];
int par[1010];
int inf = 1e9;
void dijkstra(int u) {
	for (int i = 1; i <= n; i++)dist[i] = inf;
	priority_queue<piii, vector<piii>, greater<piii>>pq;//값,인덱스,부모인덱스
	pq.push({ {0,u},-1 });
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		if (dist[t.first.second] != inf)continue;
		dist[t.first.second] = t.first.first;
		par[t.first.second] = t.second;
		for (auto i : adj[t.first.second]) {
			if (dist[i.first] == inf) {
				pq.push({ {t.first.first + i.second,i.first},t.first.second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	int a, b; cin >> a >> b;
	dijkstra(a);
	cout << dist[b]<<'\n';
	int k=b;
	vector<int>v;
	v.push_back(b);
	while (1) {
		if (par[k] == -1)break;
		v.push_back(par[k]);
		k = par[k];
	}
	reverse(v.begin(), v.end());
	cout << v.size()<<'\n';
	for (auto i : v) {
		cout << i << ' ';
	}
	return 0;
}