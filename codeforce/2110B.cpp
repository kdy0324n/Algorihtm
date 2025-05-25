#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int s = 0;
		int cnt = 0;
		string str; cin >> str;
		for (auto& i : str) {
			if (i == '(')s++;
			else s--;
			if (s == 0)cnt++;
		}
		if (cnt > 1)cout << "yes" << '\n';
		else cout << "no" << '\n';
	}


	return 0;
}