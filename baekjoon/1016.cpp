#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll s, e;
bool ischk[1000010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(ischk, true, sizeof(ischk));
	cin >> s >> e;
	for (ll i = 2; i <= 1000000; i++) {
		ll t = i * i;
		if (t > e)break;
		ll n = s / t;
		if (n*t<s)n++;
		while (n*t <= e) {
			ischk[n * t - s] = false;
			n++;
		}
	}
	int ans=0;
	for (int i = 0; i <= e - s; i++)if (ischk[i])ans++;
	cout << ans;

	return 0;
}