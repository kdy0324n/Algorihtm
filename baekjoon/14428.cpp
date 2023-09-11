#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n, m;
vector<pii>tree;
int arr[100010];
void update(int n, int s, int e, int idx, int val) {
	if (s == e) {
		tree[n] = { val,idx };
		return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update(lch, s, mid, idx, val);
	else update(rch, mid + 1, e, idx, val);
	tree[n] = min(tree[lch], tree[rch]);
}

pii query(int n, int s, int e, int l, int r) {
	if (e < l || r < s)return { 1e9,1e9 };
	if (l <= s && e <= r)return tree[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return min(query(lch, s, mid, l, r), query(rch, mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	tree.resize(n * 4, { 1e9 + 10 ,1e9+10});
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		update(1, 1, n, i, a);
	}
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			auto i = query(1, 1, n, b, c);
			cout << i.second << '\n';
		}
	}

	return 0;
}