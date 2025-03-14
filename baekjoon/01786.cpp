#include<bits/stdc++.h>
using namespace std;

vector<int>getpi(string str) {
	
	int n = str.size();
	vector<int>table(n,0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && str[i] != str[j])j = table[j - 1];
		if (str[j] == str[i]) {
			j++;
			table[i] = j;
		}
	}
	return table;
}

vector<int>kmp(string parrent, string str) {
	vector<int>ans;
	vector<int>pi = getpi(str);
	int n = parrent.size();
	int m = str.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && parrent[i] != str[j])j = pi[j - 1];

		if (str[j] == parrent[i]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string parrent, str;
	getline(cin, parrent);
	getline(cin, str);
	vector<int>ans = kmp(parrent, str);
	cout << ans.size() << '\n';
	for (auto i : ans)cout << i+1 << ' ';

	return 0;
}