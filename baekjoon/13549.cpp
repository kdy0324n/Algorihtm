#include<bits/stdc++.h>
using namespace std;

int n, k;

int dp[200010];
int inf = 1e9;
using pii = pair<int, int>;

queue<pii>q;

void bfs() {
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (dp[t.first] > t.second) {
			dp[t.first] = t.second;
			int n_idx, n_time;

			n_idx = t.first + 1;
			n_time = t.second + 1;
			if (n_idx <= 200000) {
				q.push({ n_idx,n_time });
			}

			n_idx = t.first - 1;
			n_time = t.second + 1;
			if (n_idx >= 0) {
				q.push({ n_idx,n_time });
			}

			n_idx = t.first * 2;
			n_time = t.second;
			if (0 <= n_idx && n_idx <= 200000) {
				if (n_idx == 0)continue;
				q.push({ n_idx,n_time });
			}
		}		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	

	cin >> n >> k;
	for (int i = 0; i <= 200000; i++)dp[i] = inf;
	q.push({n,0});
	bfs();
	cout << dp[k];
	return 0;
}