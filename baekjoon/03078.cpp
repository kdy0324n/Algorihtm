#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<string>v;
long long chk[22];
long long ans;
queue<string>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string  str;
		cin >> str;

		int a = str.size();
		ans += chk[a];

		q.push(str);
		chk[a]++;

		if (i < k)continue;
		int b = q.front().size();
		chk[b]--;
		q.pop();
	}
	cout << ans;

	return 0;
}