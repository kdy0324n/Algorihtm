#include<bits/stdc++.h>
using namespace std;

int T, n;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
int tree[400010];

void update(int n, int s, int e, int idx, int val) {
    if (s == e) {
        tree[n] += val; return;
    }
    int mid = (s + e) / 2;
    int lch = n * 2;
    int rch = n * 2 + 1;
    if (idx <= mid)update(lch, s, mid, idx, val);
    else update(rch, mid + 1, e, idx, val);
    tree[n] = tree[lch] + tree[rch];
}
int query(int n, int s, int e, int l, int r) {
    if (e < l || r < s)return 0;
    if (l <= s && e <= r)return tree[n];
    int mid = (s + e) / 2;
    int lch = n * 2;
    int rch = n * 2 + 1;
    return query(lch, s, mid, l, r) + query(rch, mid + 1, e, l, r);
}
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        ans = 0;
        memset(tree, 0, sizeof(tree));
        int n; cin >> n;
        map<int, int>m;
        vector<pii>arr;
        vector<int>y_sort;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            arr.emplace_back(-a, b);
            y_sort.push_back(b);
        }

        sort(arr.begin(), arr.end());
        sort(y_sort.begin(), y_sort.end());
        for (int i = 0; i < n; i++) {
            m[y_sort[i]] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            ans += query(1, 1, n, 1, m[arr[i].second]);
            update(1, 1, n, m[arr[i].second], 1);
        }
        cout << ans << '\n';
    }

    return 0;
}