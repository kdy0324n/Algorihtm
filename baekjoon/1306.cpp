#include<bits/stdc++.h>
using namespace std;

int n, m;

int tree[4000010];

void update(int n, int s, int e, int idx, int val) {
	if (s == e) {
		tree[n] = max(tree[n],val); return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update(lch, s, mid, idx, val);
	else update(rch, mid+1, e, idx, val);
	tree[n] = max(tree[lch], tree[rch]);
}
int query(int n, int s, int e, int l, int r) {
	if (e < l || r < s)return 0;
	if (l <= s && e <= r)return tree[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return max(query(lch, s, mid, l, r), query(rch, mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	m = m * 2 - 1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		update(1, 1, n, i, a);
	}
	for (int i = m; i <= n; i++) {
		cout << query(1, 1, n, i - m + 1, i)<< ' ';
	}

	return 0;
}