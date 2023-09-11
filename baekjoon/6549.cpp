/*#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
stack<int>st;
ll arr[100010];
ll ans = 0;

ll dfs(int s, int e) {
	if(s == e)return arr[e];
	int mid = (s + e) / 2;
	ll ret = max(dfs(s, mid), dfs(mid + 1, e));

	ll lo = mid, hi = mid + 1;
	ll h = min(arr[lo], arr[hi]);
	ret = max(ret, h * 2);

	while (s < lo || hi < e) {
		if (hi < e && (lo == s || arr[lo - 1] < arr[hi + 1])) {
			hi++;
			h = min(h, arr[hi]);
		}
		else {
			lo--;
			h = min(h, arr[lo]);
		}
		ret = max(ret, h * (hi - lo +1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		cin >> n;
		ans = 0;
		if (n == 0)break;
		for (int i = 1; i <= n; i++)cin >> arr[i];

		cout << dfs(1, n)<<'\n';
	}
	

	return 0;
}*///이분 탐색 풀이

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
stack<int>st;
int arr[100010];
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++)cin >> arr[i];
		st.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (!st.empty() && arr[st.top()] > arr[i]) {
				int t = st.top();
				st.pop();
				ans = max(ans, arr[t] * ll(i - st.top() - 1));
			}
			st.push(i);
		}
		cout << ans << '\n';
		while (!st.empty())st.pop();
		memset(arr, 0, sizeof(arr));
		ans = 0;
	}
	return 0;
}//스택 풀이