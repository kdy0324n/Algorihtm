#include<bits/stdc++.h>
using namespace std;

int tree1[400010];//최소 구간 트리
int tree2[400010];//최대 구간 트리


void update1(int n, int s, int e, int idx, int val) {
	if (s == e) {
		tree1[n] = val; return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update1(lch, s, mid, idx, val);
	else update1(rch, mid + 1, e, idx, val);
	tree1[n] = min(tree1[lch], tree1[rch]);
}
int query1(int n, int s, int e, int l, int r) {
	if (e < l || r < s)return 1e9;
	if (l <= s && e <= r)return tree1[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return min(query1(lch, s, mid, l, r), query1(rch, mid + 1, e, l, r));
}
void update2(int n,int s,int e, int idx, int val) {
	if (s == e) {
		tree2[n] = val; return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	if (idx <= mid)update2(lch, s, mid, idx, val);
	else update2(rch, mid + 1, e, idx, val);
	tree2[n] = max(tree2[lch], tree2[rch]);
}
int query2(int n, int s, int e, int l, int r) {
	if (e < l || r < s)return 0;
	if (l <= s && e <= r)return tree2[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return max(query2(lch, s, mid, l, r), query2(rch, mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n * 4; i++) {
			tree1[i] = 1e9;
			tree2[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			update1(1, 1, n, i, a);
			update2(1, 1, n, i, a);
		}
		while (q--) {
			int a, b; cin >> a >> b;
			a++, b++;
			cout << query2(1, 1, n, a, b) - query1(1, 1, n, a, b) << '\n';
		}
	}


	return 0;
}