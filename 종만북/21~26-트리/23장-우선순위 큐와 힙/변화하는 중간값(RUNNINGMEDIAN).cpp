#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using ll = long long;

int n;
ll arr[200010];
ll const Mod = 20090711;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[0] = 1983;
	int t; cin >> t;
	while (t--) {
		priority_queue<ll, vector<ll>, greater<ll>>Min_pq;
		priority_queue<ll>Max_pq;
		Max_pq.push(1983);
		ll ans = 1983;
		cin >> n;
		ll a, b; cin >> a >> b;
		for (int i = 1; i < n; i++) {
			ll t = (arr[i - 1] * a + b) % Mod;
			arr[i] = t;
			if (Max_pq.empty()) {
				Max_pq.push(t);
			}
			else {
				if (Max_pq.size() == Min_pq.size()) {
					Max_pq.push(t);
				}
				else {
					Min_pq.push(t);
				}
				while (Max_pq.top() > Min_pq.top()) {
					int a = Max_pq.top(); Max_pq.pop();
					int b = Min_pq.top(); Min_pq.pop();
					Max_pq.push(b);
					Min_pq.push(a);
				}
			}
			ans += Max_pq.top();
			//cout << Max_pq.top() << '\n';
			
			ans %= Mod;
		}
		cout << ans << '\n';
	}

	return 0;
}