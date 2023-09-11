#include<iostream>
#include<vector>
using namespace std;

int t;

vector<int>getpi(string str) {

	int n = str.size();
	vector<int>table(n, 0);
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

int kmp(string parrent, string str) {
	vector<int>ans;
	vector<int>pi = getpi(str);
	int n = parrent.size();
	int m = str.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && parrent[i] != str[j])j = pi[j - 1];

		if (str[j] == parrent[i]) {
			if (j == m - 1) {
				return i - m + 1;
			}
			else {
				j++;
			}
		}
	}
}

int shift(string a, string b) {
	int re = kmp(a + a, b);
	return re;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	string par, str;
	while (t--) {
		int n;
		cin >> n;
		cin >> par;
		int ans = 0;
		bool type = false;//true면 시계방향 false면 반시계방향
		for (int i = 1; i <= n; i++) {
			cin >> str;
			//cout << par << ' ' << str;
			if(type)
				ans+=shift(par, str);
			else 
				ans+=shift(str, par);
			par = str;
			type = !type;
		}
		cout << ans << '\n';
	}

	return 0;
}