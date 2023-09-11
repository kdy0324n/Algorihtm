#include<bits/stdc++.h>
using namespace std;

int n, m;

int v1, v2;
using pii = pair<int, int>;

vector<pii>adj[810];

int dist[810];
const int inf = 1e8;

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
				pq.push({ i.second + t.first,i.first });
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
		adj[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	int q, w, e;
	dijkstra(v1);
	q = dist[1];
	w = dist[v2];
	e = dist[n];

	int q1,w1,e1;
	dijkstra(v2);
	q1 = dist[1];
	w1 = dist[v1];
	e1 = dist[n];

	int ans = min(q1 + e, q + e1);
	ans += w;
	if (ans >= inf)cout << -1;
	else cout << ans;

	return 0;
}