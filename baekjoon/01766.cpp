#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int>adj[40000];
int inde[40000];

void kahn() {
	vector<int>tp;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1; i <= n; i++)if (inde[i] == 0)pq.push(i);
	while (!pq.empty()) {
		int t = pq.top();
		tp.push_back(t);
		pq.pop();
		for (auto i : adj[t]) {
			inde[i]--;
			if (inde[i] == 0)pq.push(i);
		}
	}
	for (int i = 0; i < tp.size(); i++)cout << tp[i] << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		inde[b]++;
	}
	kahn();

	return 0;
}