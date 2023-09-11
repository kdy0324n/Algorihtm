#include<queue>
#include<iostream>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		priority_queue<int,vector<int>,greater<int>>pq;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			pq.push(a);
		}
		int ans = 0;
		while (pq.size() != 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();

			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << '\n';
	}


	return 0;
}