#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;

using ll = long long;
int n, m;
ll A[110];
ll B[110];
int dp[110][110];


int jlis(int indexA, int indexB) {
	int &ret = dp[indexA][indexB];
	if (ret)return ret;

	ret = 2;
	ll ele = max(A[indexA], B[indexB]);
	for (int i = indexA + 1; i <= n; i++) {
		if (ele < A[i]) ret = max(ret, jlis(i, indexB)+1);
	}
	for (int i = indexB + 1; i <= m; i++) {
		if (ele < B[i]) ret = max(ret, jlis(indexA, i) + 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)cin >> A[i];
		for (int i = 1; i <= m; i++)cin >> B[i];
		A[0] = B[0] = LLONG_MIN;
		cout << jlis(0, 0)-2 << '\n';
	}


	return 0;
}