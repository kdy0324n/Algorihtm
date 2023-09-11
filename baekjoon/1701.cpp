#include<bits/stdc++.h>
using namespace std;

vector<int>pi(string str) {
	int n = str.size();
	vector<int>table(n, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && str[i] != str[j])j = table[j - 1];
		if (str[i] == str[j]) {
			j++;
			table[i] = j;
		}
	}
	return table;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	string str; cin >> str;
	for (int i = 0; i < str.size();i++) {
		auto table = pi(str.substr(i,str.size()));
		for (auto j : table)ans = max(ans, j);
	}
	
	
	cout << ans;
	return 0;
}