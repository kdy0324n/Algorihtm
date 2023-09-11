#include<bits/stdc++.h>
using namespace std;

int n;
bool check(string str) {
	int size = str.size();
	if (size <= 2)return false;

	
	int mid = size / 2;
	for (int i = 2; i <= mid; i++) {
		string left = str.substr(size - i * 2, i);
		string right = str.substr(size - i, i);
		if (left == right)return true;
	}
	return false;
}
bool flag = false;
void dfs(int cur, string str) {
	if (check(str))return;
	if (cur >= n) {
		cout << str; flag = true;
		return;
	}
	int t = str.size()-1;
	if (str[t] == '1') {
		dfs(cur + 1, str + '2'); if (flag)return;
		dfs(cur + 1, str + '3'); if (flag)return;
	}
	else if (str[t] == '2') {
		dfs(cur + 1, str + '1'); if (flag)return;
		dfs(cur + 1, str + '3'); if (flag)return;
	}
	else {
		dfs(cur + 1, str + '1'); if (flag)return;
		dfs(cur + 1, str + '2'); if (flag)return;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dfs(1,"1");

	return 0;
}