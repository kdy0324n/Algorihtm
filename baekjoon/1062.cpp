#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int>word;
int chk;
int ans;
void dfs(int start, int cnt) {
	if (cnt == k) {
		int a = 0;
		for (auto &i : word) {
			if ((i & chk)==i)a++;
		}
		ans = max(ans, a);
		return;
	}
	for (int i = start; i < 26; i++) {
		int t = (1 << i);
		if ((chk & t) == t)continue;
		chk |= t;
		dfs(i + 1, cnt + 1);
		chk &= ~t;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		int a = 0;
		for (auto &j : str)a |= (1 << (j-'a'));
		word.emplace_back(a);
	}
	if (k < 5)cout << 0;
	else if (k == 26)cout << n;
	else {
		chk |= (1 << ('a' - 'a'));
		chk |= (1 << ('n' - 'a'));
		chk |= (1 << ('t' - 'a'));
		chk |= (1 << ('i' - 'a'));
		chk |= (1 << ('c' - 'a'));
		k -= 5;
		dfs(0, 0);
		cout << ans;
	}
	

	return 0;
}