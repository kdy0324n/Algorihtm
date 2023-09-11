#include<bits/stdc++.h>
using namespace std;

int n, m;
int remem;
int arr[10010];
vector<int>v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 26; i++)remem |= (1 << i);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (auto j : str) {
			arr[i] |= (1 << (j - 'a'));
		}
	}
	for (int i = 1; i <= m; i++) {
		int re=0;
		int a;
		char b;
		cin >> a>>b;
		int t = b - 'a';
		remem ^= (1<<t);
		for (int i = 1; i <= n; i++) {
			if ((arr[i] & remem)==arr[i])re++;
		}
		v.emplace_back(re);
	}
	for (auto i : v)cout << i << '\n';

	return 0;
}