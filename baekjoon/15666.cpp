#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int>v;
set<vector<int>>ans;

void dfs(int cur, int idx) {
	if (cur > m) {
		ans.insert(v);
		return;
	}
	for (int i = idx; i <= n; i++) {
		v.push_back(arr[i]);
		dfs(cur + 1, i);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	dfs(1, 1);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}