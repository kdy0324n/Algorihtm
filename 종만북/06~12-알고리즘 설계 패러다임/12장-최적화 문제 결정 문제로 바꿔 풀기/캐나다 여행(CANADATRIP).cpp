#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
struct dd {
	int a, b, c;
};
dd arr[5010];
bool decision(int x) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (x >= arr[i].a) {
			ret += (min(x, arr[i].b) - arr[i].a) / arr[i].c + 1;
		}
	}
	return ret >= k;
}
int solve() {
	int l = -1, r = 9000000;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (decision(mid)) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[i].a = a - b;
			arr[i].b = a;
			arr[i].c = c;
		}
		cout << solve()<<'\n';
	}

	return 0;
}