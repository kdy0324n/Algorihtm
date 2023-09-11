#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int chk[10];
vector<int>v;
set<vector<int>>ans;

void dfs(int cur) {
	if (cur > m) {
		ans.insert(v);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i])continue;
		chk[i] = 1;
		v.push_back(arr[i]);
		dfs(cur + 1);
		v.pop_back();
		chk[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(1);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}