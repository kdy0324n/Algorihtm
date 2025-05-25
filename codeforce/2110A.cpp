#include<bits/stdc++.h>
using namespace std;
 
 
using pii = pair<int, int>;
 
struct node {
	int l, r, cnt;
};
 
vector<int>ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int>arr;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		queue<node>q;
		q.push({ 0,n - 1,0 });
 
		while (!q.empty()) {
			node t = q.front();
			q.pop();
 
			if ((arr[t.l] + arr[t.r]) % 2 == 0) {
				ans.push_back(t.cnt); break;
			}
 
			q.push({ t.l + 1,t.r,t.cnt + 1 });
			q.push({ t.l,t.r - 1,t.cnt + 1 });
		}
	}
	for (auto& i : ans) {
		cout << i << '\n';
	}
 
 
	return 0;
}