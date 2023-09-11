#include<iostream>
#include<vector>
#include<set>
#include<string.h>
using namespace std;

int arr[10010];
int dp[10010];
int dd(int idx, int m) {
	vector<int>v;
	set<int>s;
	for (int i = idx; i < idx + m; i++)v.push_back(arr[i]), s.insert(arr[i]);
	//1 . 모든 숫자가 같을때
	if (s.size() == 1)return 1;

	//2. 숫자가 1씩 단조 증가하거나, 단조 감소할때
	int tmp = arr[idx + 1] - arr[idx];
	bool b = true;
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] == tmp)continue;
		b = false;
	}
	//등차수열에서 단조면 2, 그냥 등차 수열 이면 5
	if (b) {
		if (tmp == 1 || tmp == -1)return 2;
		else return 5;
	}
	b = true;
	for (int i = 2; i < m; i++) {
		if (v[i - 2] == v[i])continue;
		b = false;
	}
	if (b)return 4;

	return 10;

}
int inf = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>ans;
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int n = str.size();
		for (int i = 0; i < n; i++) {
			arr[i + 1] = str[i] - 48;
		}
		dp[1] = inf;
		dp[2] = inf;
		dp[3] = dd(1, 3);
		dp[4] = dd(1, 4);
		dp[5] = dd(1, 5);
		for (int i = 6; i <= n; i++) {
			int ret = inf;
			for (int j = 3; j <= 5; j++) {
				int a = dd(i - j + 1, j);
				ret = min(ret, dp[i - j] + a);
			}
			dp[i] = ret;
		}
		ans.push_back(dp[n]);
	}
	for (auto i : ans) {
		cout << i << '\n';
	}

	return 0;
}