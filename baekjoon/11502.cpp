#include<bits/stdc++.h>
using namespace std;

int n=3000;
bool isPrime[3010];

void eratos() {
	int sqrtn = int(sqrt(n));
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
struct dd {
	int q, w, e;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	eratos();

	while (t--) {
		int k;
		cin >> k;
		bool b = false;
		vector<int>v;
		for (int i = 2; i <= k; i++)if (isPrime[i])v.push_back(i);
		vector<dd>a;
		for (auto i : v)for (auto j : v)a.push_back({ i + j, i, j });
		for (auto i : a) {
			if (k < i.q)continue;
			if (isPrime[k - i.q]) {
				vector<int>arr;
				arr.emplace_back(i.w);
				arr.emplace_back(i.e);
				arr.emplace_back(k - i.q);
				sort(arr.begin(), arr.end());
				for (auto j : arr)cout << j << ' ';
				b = true;
				break;
			}
		}
		if (b)cout << '\n';
		else cout <<-1<< '\n';
	}

	return 0;
}