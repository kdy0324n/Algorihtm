#include<bits/stdc++.h>
using namespace std;

int n;

vector<int>adj[100010];

int arr[100010];
int chk[100010];
void dfs( int cur) {

	for (auto i : adj[cur]) {
		if (chk[i])continue;
		chk[i] = 1;
		arr[i] = cur;
		dfs(i);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	chk[1] = 1;
	dfs(1);
	for (int i = 2; i <= n; i++)cout << arr[i] << '\n';
	return 0;
}