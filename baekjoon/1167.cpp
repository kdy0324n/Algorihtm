#include<bits/stdc++.h>
using namespace std;

int n;
using ll = long long;
using pii = pair<int, int>;
vector<pii>adj[100010];
int chk[100010];
int idx; ll maxval;

void dfs(int cur, ll sum) {
	if (sum > maxval) {
		maxval = sum;
		idx = cur;
	}
	for (auto i : adj[cur]) {
		if (chk[i.first])continue;
		chk[i.first] = 1;
		dfs(i.first, sum + i.second);
		chk[i.first] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a,b,c; cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)break;
			cin >> c;
			adj[a].push_back({ b,c });
		}
	}
	chk[1] = 1;
	dfs(1, 0);
	chk[1] = 0;

	maxval = 0;
	chk[idx] = 1;
	dfs(idx, 0);
	cout << maxval;


	return 0;
}