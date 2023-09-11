#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int n, m;

int chk[11];
int ans;
bool check() {
	for (int i = 0; i < n; i++) {
		if (!chk[i])return false;
	}
	return true;
}

void dfs(vector<int>adj[11],int cur) {

	if (check()) {
		ans++;
		return;
	}


	for (int i = cur; i < n; i++) {
		if (chk[i])continue;
		bool b = true;
		for (auto j : adj[i]) {
			if (chk[j])continue;
			chk[i] = 1;
			chk[j] = 1;
			dfs(adj,i+1);
			chk[i] = 0;
			chk[j] = 0;
			b = false;
		}
		if (b)return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>v;
	int t; cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		memset(chk, 0, sizeof(chk));
		vector<int>adj[11];
		for (int i = 1; i<= m; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b)swap(a, b);
			adj[a].push_back(b);

		}
		dfs(adj,0);
		v.push_back(ans);
	}
	for (auto i : v) {
		cout << i << '\n';
	}

	return 0;
}