#include<bits/stdc++.h>
using namespace std;

int n, s;
int arr[44];

void solve(int l, int r, int hap,vector<int>& aa) {
	if (l == r) {
		aa.push_back(hap);
		return;
	}
	solve(l + 1, r, hap + arr[l], aa);
	solve(l + 1, r, hap, aa);
}
long long ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	vector<int>a, b;
	for (int i = 0; i < n; i++)cin >> arr[i];
	int mid = n / 2;
	solve(0, mid+1, 0, a);
	solve(mid + 1, n, 0, b);
	sort(b.begin(), b.end());
	for (auto i : a) {
		auto l = lower_bound(b.begin(), b.end(), s - i);
		auto r = upper_bound(b.begin(), b.end(), s - i);
		ans += r - l;
	}
	if (s == 0)ans--;
	cout << ans;

	return 0;
}