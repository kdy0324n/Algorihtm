/*#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int>adj[110];
vector<int>back_adj[110];

int val;
int chk[110];
void dfs(int cur) {
	for (auto i : adj[cur]) {
		if (chk[i])continue;
		chk[i] = 1;
		val++;
		dfs(i);
	}
}

void back_dfs(int cur) {
	for (auto i : back_adj[cur]) {
		if (chk[i])continue;
		chk[i] = 1;
		val++;
		back_dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		back_adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		int ans = 0;
		val = 0;
		chk[i] = 1;
		dfs(i);
		ans += val;

		memset(chk, 0, sizeof(chk));
		val = 0;
		chk[i] = 1;
		back_dfs(i);
		ans += val;
		ans++;
		cout << n-ans << '\n';
	}
	return 0;
}*///dfs 풀이
#include<bits/stdc++.h>
using namespace std;

int n, m;

int dist[110][110];
int dist2[110][110];
int inf = 1e8;


void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			dist[i][j] = inf;
			dist2[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist2[b][a] = 1;
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] < inf)ans++;
			if (dist2[i][j] < inf)ans++;
		
		}
		ans--;
		cout << n-ans << '\n';
	}
	return 0;
}//플로이드 와샬 풀이