#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int dp[110][110];
bool solve(string wild, string file) {
	if (dp[wild.size()][file.size()])return false;
	dp[wild.size()][file.size()] = 1;
	int pos = 0;
	while (pos < wild.size() && pos < file.size()) {
		if (wild[pos] != file[pos] && wild[pos] != '?')break;
		pos++;
	}

	if (pos == wild.size())
		return pos == file.size();

	if (wild[pos] == '*') {
		for (int i = 0; i + pos <= file.size(); i++) {
			if (solve(wild.substr(pos + 1), file.substr(pos + i)))return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vector<string>v;
		string wild, file;
		cin >> wild;
		int n;
		cin >> n;
		while (n--) {
			memset(dp, 0, sizeof(dp));
			cin >> file;
			if (solve(wild, file))v.push_back(file);
		}
		sort(v.begin(), v.end());
		for (auto i : v) {
			cout << i << '\n';
		}
	}

	

	return 0;
}