#include<bits/stdc++.h>
using namespace std;

int indee[30];
int n;
vector<vector<int>>getadj(vector<string>str) {
	vector<vector<int>>adj;
	adj.resize(30);

	int i = 0;
	for (int j = 1; j < str.size(); j++) {
		int len = min(str[i].size(), str[j].size());
		for (int k = 0; k < len; k++) {
			if (str[i][k] == str[j][k])continue;
			int a = str[i][k] - 96;
			int b = str[j][k] - 96;
			adj[a].emplace_back(b);
			indee[b]++;
			break;
		}
		i++;
	}
	return adj;
}

void kahn(vector<vector<int>>adj) {
	queue<int>q;
	for (int i = 1; i <= 26; i++)if (indee[i] == 0)q.push(i);
	vector<int>tp;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		tp.push_back(t);
		for (auto i : adj[t]) {
			indee[i]--;
			if (indee[i] == 0)q.push(i);
		}
	}
	if (tp.size() != 26)cout << "INVALID HYPOTHESIS";
	else {
		for (auto i : tp)cout << char(i + 96);
	}
	cout << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(indee, 0, sizeof(indee));
		cin >> n;
		vector<string>v;
		for (int i = 1; i <= n; i++) {
			string str; cin >> str;
			v.push_back(str);
		}
		auto adj = getadj(v);
		kahn(adj);
	}

	return 0;
}