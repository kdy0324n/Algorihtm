#include<bits/stdc++.h>
using namespace std;

int n;
int m;
using pii = pair<int, int>;
vector<pii>adj[1010];
int dist[1010];
int inf = 1e9;
void dijkstra(int u) {
	for (int i = 1; i <= n; i++)dist[i] = inf;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({ 0,u });
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		if (dist[t.second] != inf)continue;
		dist[t.second] = t.first;
		for (auto i : adj[t.second]) {
			if (dist[i.first] == inf) {
				pq.push({ t.first + i.second,i.first });
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
	cout << dist[b];

	return 0;
}