#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, long long>> adj[5010];
int chk[5010];
long long ans;


void dfs(int idx,long long cnt) {

	if (idx != 1 && adj[idx].size() == 1) {
		ans = max(cnt, ans);
		return;
	}

	for (int i = 0; i < adj[idx].size(); i++) {
		int t = adj[idx][i].first;
		if (chk[t])
			continue;
		chk[t] = 1;

		dfs(t, cnt + adj[idx][i].second);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	
	chk[1] = 1;
	dfs(1, 0);
	cout << ans;
	return 0;
}