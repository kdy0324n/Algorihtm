/*#include<bits/stdc++.h>
using namespace std;

int n, m, r;
int w[110];
int arr[110][110];
int inf = 100000;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}
int ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)arr[i][j] = inf;
	for (int i = 1; i <= n; i++) { cin >> w[i], arr[i][i] = 0; }
	while (r--) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == inf)continue;
			if (arr[i][j] > m)continue;
			tmp += w[j];
		}
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}*/ //플로이드 와샬

//다익스트라
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, r, w[110];
vector<pii>adj[110];

int dist[110];
int inf = 100000;
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
int ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= r; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] > m)continue;
			tmp += w[j];
		}
		ans = max(ans, tmp);
	}
	cout << ans;

	return 0;
}