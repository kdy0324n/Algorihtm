#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int>v;
bool isPrime[1010];

void eratos() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sq = int(sqrt(n));

	for (int i = 2; i <= sq; i++) {
		if (isPrime[i]) {
			isPrime[i] = false;
			v.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				if (!isPrime[j])continue;
				isPrime[j] = false;
				v.push_back(j);
			}
		}
	}
	for (int i = 2; i <= n; i++)if (isPrime[i])v.push_back(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> k;
	eratos();
	cout << v[k - 1];
	return 0;
}