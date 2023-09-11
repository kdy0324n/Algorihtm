#include<bits/stdc++.h>
using namespace std;

using ll = long long;
//1. 소수면 -1
//2. 합성수인데 소인수가 짝수면 i*(i+1)
//3. 합성수인데 소인수가 홀수면 i*(i+1)을하다가 마지막 3개 남았을때 세개를 한꺼번에 곱함

bool isPrime(ll n) {
	if (n == 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	ll sqrtn = ll(sqrt(n));
	for (ll i = 3; i <= sqrtn; i += 2)if (n % i == 0)return false;
	return true;
}

vector<ll>isfactorization(ll n) {
	vector<ll>ret;
	ll sqrtn = ll(sqrt(n));

	for (ll i = 2; i <= sqrtn; i++) {
		while (n % i == 0) {
			ret.emplace_back(i), n /= i;
		}
	}
	if (n != 1)ret.emplace_back(n);
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	if (isPrime(n))cout << -1;
	else {
		vector<ll>v = isfactorization(n);
		ll m = v.size();
		if (v.size() % 2 == 0) {
			for (ll i = 0; i < m; i += 2) {
				cout << v[i] * v[i + 1]<<' ';
			}
		}
		else {
			for (ll i = 0; i < m - 3; i += 2) {
				cout << v[i] * v[i + 1] << ' ';
			}
			cout << v[m - 3] * v[m - 2] * v[m - 1];
		}
	}
	return 0;
}