#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<int>v(n + 1);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			if (v[i] == 0)flag = false;
		}
		if (flag) {
			cout << "YES\n";
			continue;
		}
		flag = true;
		for (int i = 2; i <= n; i++) {
			if (v[i] == 0 && v[i - 1] == 0) {
				cout << "YES\n";
				flag = false;
				break;
			}
		}
		if (!flag)continue;
		cout << "NO\n";
	}



	return 0;
}