#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	while (cin >> t) {
		set<int>s;
		for (int i = 1; i <= t; i++) {
			string str; cin >> str;
			int m = 0;
			for (auto j : str) {
				m |= (1 << (j - '0'));
			}
			s.insert(m);
		}
		cout << s.size()<<'\n';
	}


	return 0;
}