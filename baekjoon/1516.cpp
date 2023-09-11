#include<bits/stdc++.h>
using namespace std;

int n;
using pii = pair<int, int>;
vector<int>adj[510];
int cost[510];
int indee[510];
int dp[510];

void kahn() {
	queue<int>q;
	for (int i = 1; i <= n; i++)if (indee[i] == 0)q.push(i);

	vector<int>tp;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		dp[t] += cost[t];
		tp.push_back(t);
		for (auto i : adj[t]) {
			indee[i]--;
			if (indee[i] == 0) {
				q.push(i);
			}
			dp[i] = max(dp[i], dp[t]);
		}
	}
	for (int i = 1; i <= n; i++)cout << dp[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		int a;
		while (1) {
			cin >> a;
			if (a == -1)break;
			indee[i]++;
			adj[a].push_back(i);
		}
	}
	kahn();
	return 0;
}