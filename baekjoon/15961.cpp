#include<bits/stdc++.h>
using namespace std;

int n, d, k, c;
int chk[3010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		v.push_back(v[i]);
	}
	int cnt = 1;
	chk[c] = 1;
	int re = 0;
	queue<int>q;
	for (int i = 0; i < v.size(); i++) {
		re = max(re, cnt);
		int a = v[i];
		q.push(a);
		chk[a]++;
		if (chk[a] == 1)cnt++;
		if (i < k)continue;
		int b = q.front();
		if (chk[b] == 1)cnt--;
		chk[b]--;
		q.pop();
	}
	cout << re;
	return 0;
}