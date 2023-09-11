#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[55][55];
using pii = pair<int, int>;
vector<pii>home;
vector<pii>chicken;
int chk[14];
int ans = 1e9;
int limit;

int dist() {//거리 계산
	int ret = 0;
	for (auto i : home) {
		int y1 = i.first;
		int x1 = i.second;
		int k = 1000;
		for (int j = 0; j < chicken.size(); j++) {
			if (chk[j] == 0)continue;
			int y2 = chicken[j].first;
			int x2 = chicken[j].second;
			k = min(k, abs(y1 - y2) + abs(x1 - x2));
		}
		ret += k;
	}
	return ret;
}

void dfs(int idx, int level) {
	if (level > m) {
		ans = min(ans, dist());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (chk[i])continue;
		chk[i] = 1;
		dfs(i,level + 1);
		chk[i] = 0;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)home.push_back({ i,j });
			if (arr[i][j] == 2)chicken.emplace_back(i, j);
		}
	}
	dfs(0, 1);
	cout << ans;
	return 0;
}