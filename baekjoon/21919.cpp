#include<bits/stdc++.h>
using namespace std;

bool isPrime[1000010];
const int N = 1000000;
using ll = long long;
void eratos() {
	memset(isPrime, 1, sizeof(isPrime));
	int sqrtn = int(sqrt(N));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

ll gcd(ll a, ll b) {
	if (a == 0)return b;
	gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}
vector<int>arr;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	eratos();

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (isPrime[a])arr.emplace_back(a);
	}
	if (arr.size() == 0)cout << -1;
	else {
		long long ans = 1;
		for (auto i : arr)ans = lcm(ans, i);
		cout << ans;
	}
	
	return 0;
}