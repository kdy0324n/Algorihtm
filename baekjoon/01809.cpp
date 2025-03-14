#include<bits/stdc++.h>
using namespace std;

int n, s;
int arr[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		k += arr[i];
	}
	if (k < s) {
		cout << 0;
		return 0;
	}
	int r = 1, l = 1;
	int t = 0;
	int ans = 1e9;
	while (l <= r && r <= n) {
		while (r <= n && t < s) {
			t += arr[r];
			r++;
		}
		while (l <= r && s <= t) {
			t -= arr[l];
			l++;
		}
		ans = min(ans, r - l+1);
	}
	cout << ans;
	return 0;
}