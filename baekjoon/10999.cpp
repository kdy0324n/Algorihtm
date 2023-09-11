#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll tree[4000010];
ll lazy[4000010];

void update(int n, int s, int e, int idx, ll val) {
	if (s == e) {
		tree[n] = val;
		return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update(lch, s, mid, idx, val);
	else update(rch, mid + 1, e, idx, val);
	tree[n] = tree[lch] + tree[rch];
}
void propagate(int n, ll s, ll e) {
	if (!lazy[n])return;
	tree[n] += (e - s + 1) * lazy[n];
	if (s != e) {
		int lch = n * 2;
		int rch = n * 2 + 1;;
		lazy[lch] += lazy[n];
		lazy[rch] += lazy[n];
	}	
	lazy[n] = 0;
}
void update(int n, int s, int e, int l, int r, ll val) {
	propagate(n, s, e);
	if (e<l||r<s)return;
	if (l <= s && e <= r) {
		lazy[n] += val;
		propagate(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	update(lch, s, mid, l, r, val);
	update(rch, mid + 1, e, l, r, val);
	tree[n] = tree[lch] + tree[rch];
}
ll query(int n, int s, int e, int l, int r) {
	propagate(n, s, e);
	if (e < l || r < s)return 0;
	if (l <= s && e <= r) return tree[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return query(lch, s, mid, l, r) + query(rch, mid + 1, e, l, r);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int m, k;
	cin >> m >> k;
	m += k;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		update(1, 1, n, i, a);
	}
	vector<ll>ans;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c)swap(b, c);
		if (a == 1) {
			ll d;
			cin >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			ans.push_back(query(1, 1, n, b, c));
		}
	}
	for (auto i : ans) {
		cout << i << '\n';
	}

	return 0;
}