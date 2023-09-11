#include<bits/stdc++.h>
using namespace std;

int t;
int n;
set<int>v;
map<int, int>m;
vector<int>ans;
int inf = 10000000;
struct dd {
	int x, ymin, ymax, id;
};
vector<dd>arr;

int tree[2000000];
int lazy[2000000];
void propagate(int n, int s, int e) {
	if (lazy[n] == 0)return;
	tree[n] += lazy[n];
	if (s != e) {
		lazy[n * 2] += lazy[n];
		lazy[n * 2 + 1] += lazy[n];
	}
	lazy[n] = 0;
}
void update(int n, int s, int e, int l,int r, int val) {
	propagate(n, s, e);
	if (e < l || r < s)return;
	if (l <= s && e <= r) {
		lazy[n] += val;
		propagate(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	update(lch, s, mid, l, r, val);
	update(rch,mid+1,e, l, r, val);
	tree[n] = min(tree[lch], tree[rch]);
}

int query(int n, int s, int e, int l, int r) {
	propagate(n, s, e);
	if (e < l || r < s)return inf;
	if (l <= s && e <= r)return tree[n];
	int mid = (s + e) / 2;
	int lch = n * 2;
	int rch = n * 2 + 1;
	return min(query(lch, s, mid, l, r), query(rch, mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		int id, x, ymin, ymax;
		cin >> id >> x >> ymin >> ymax;
		arr.push_back({ x,ymin,ymax,id });
		v.insert(ymin);
		v.insert(ymax);
	}
	int p = 1;
	for (auto i = v.begin(); i != v.end(); i++) {
		m[*i] = p;
		p += 2;
	}
	p -= 2;
	sort(arr.begin(), arr.end(), [](dd l, dd r) {return l.x < r.x; });

	for (auto i : arr) {
		int l = m[i.ymin];
		int r = m[i.ymax];
		int k = query(1, 1, p, l, r);
		if (k >= t)ans.push_back(i.id);
		update(1, 1, p, l, r, 1);
	}
	if (ans.empty()) { cout << 0; return 0; }
	sort(ans.begin(), ans.end());
	for (auto i : ans)cout << i << ' ';
	return 0;
}