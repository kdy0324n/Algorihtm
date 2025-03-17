#include<bits/stdc++.h>
using namespace std;

int tree[2000010];
int n,m;


void update(int n, int s, int e, int idx, int val) {
	if (s == e) {
		tree[n] += val;
		return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update(lch, s, mid, idx, val);
	else update(rch, mid + 1, e, idx, val);
	tree[n] = tree[lch] + tree[rch];
}


int query(int n, int s, int e, int l, int r) {
	if (l <= s && e <= r)return tree[n];
	if (e < l || r < s)return 0;
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return query(lch, s, mid, l, r) + query(rch, mid + 1, e, l, r);
}

int ans = 2e9;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		update(1, 1, n, i, a);
	}
	cin >> m;
	vector<int>v;
	while (m--) {
		int q; cin >> q;
		int b, c;
		if (q == 1) {
			cin >> b >> c;
			update(1, 1, n, b, c);
		}
		else {
			cin >> b;
			ans = 2e9;
			int l = 1, r = n;
			while (l <= r) {
				int mid = (l + r) / 2;
				int val = query(1, 1, n, 1, mid);
				//cout << mid << ' ' << val << ' ';
				if (val >= b) {
					ans = min(ans, mid);
					r = mid-1;
					//cout << 1;
				}
				else {
					l = mid + 1;
					//cout << 2;
				}
				//cout << '\n';
			}
			v.emplace_back(ans);
		}
	}
	for (auto i : v) {
		cout << i << '\n';
	}

	return 0;
}