#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

using pii = pair<int, int>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int t; cin >> t;
	
	while (t--) {
	  	vector<pii>aa;
		int n;
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			aa.push_back({ 0,a });
			ans += a;
		}
		for (int i = 0; i < n; i++) {
			cin >> aa[i].first;
		}
		sort(aa.rbegin(), aa.rend());
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += aa[i].second;
			ans = max(ans, tmp + aa[i].first);
		}
		cout << ans << '\n';
	}
}
