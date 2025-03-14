#include<bits/stdc++.h>
using namespace std;

struct MergeSortTree {
	vector<vector<int>>tree;
	MergeSortTree(int n) {
		tree.resize(n * 4);
	}
	void init(int n, int s, int e, vector<int>&arr) {
		if (s == e) {
			tree[n].push_back(arr[s]); return;
		}
		int mid = (s + e) / 2;
		int lch = n * 2;
		int rch = n * 2 + 1;
		init(lch, s, mid, arr);
		init(rch, mid + 1, e, arr);
		int i = 0, j = 0;
		while (i < tree[lch].size() && j < tree[rch].size()) {
			if (tree[lch][i] < tree[rch][j])tree[n].push_back(tree[lch][i]), i++;
			else tree[n].push_back(tree[rch][j]), j++;
		}
		while (i < tree[lch].size())tree[n].push_back(tree[lch][i]), i++;
		while (j < tree[rch].size())tree[n].push_back(tree[rch][j]), j++;
	}
	int query(int n, int s, int e, int l, int r, int k) {
		if (e < l || r < s)return 0;
		if (l <= s && e <= r) return lower_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
		int mid = (s + e) / 2, lch = n * 2, rch = n * 2 + 1;
		return query(lch, s, mid, l, r, k) + query(rch, mid + 1, e, l, r, k);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int>arr(n+1);
	MergeSortTree mgst(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	mgst.init(1, 1, n, arr);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		int s = -1e9;
		int e = 1e9;
		int ans = -1e9;
		while (s <= e) {
			int mid = (s + e) / 2;
			int q = mgst.query(1, 1, n, a, b, mid);
			if (q < c) {
				ans = max(ans, mid);
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
		cout << ans<<'\n';
	}

	return 0;
}