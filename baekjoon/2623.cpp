#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>adj[1010];
vector<int>inde;

bool kahn() {
	vector<int>tpsort;
	for (int i = 1; i <= n; i++) {
		if (!inde[i])tpsort.push_back(i);
	}
	for (int i = 0; i < tpsort.size(); i++) {
		for (auto& j : adj[tpsort[i]]) {
			inde[j]--;
			if (inde[j] == 0)tpsort.push_back(j);
		}
	}
	if (tpsort.size() != n)return false;

	for (auto i : tpsort)cout << i << '\n';
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	inde.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		int k=0; int b;
		for (int j = 1; j <= a; j++) {
			b = k;
			cin >> k;
			if (j == 1)continue;
			inde[k]++;
			adj[b].push_back(k);
		}
	}
	if (!kahn())cout << 0;
	return 0;
}