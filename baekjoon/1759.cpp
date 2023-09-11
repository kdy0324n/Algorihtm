#include<bits/stdc++.h>
using namespace std;


int n, m;
char arr[20];
int ans;

bool a(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')return true;
	return false;
}


void dfs(int level, string str, int one, int two) {
	if (str.size() == m) {
		if (one >= 1 && two >= 2) {
			cout << str<<'\n';
		}
		return;
	}
	if (level > n)return;
	bool b = a(arr[level]);
	dfs(level+1, str + arr[level],  b? one + 1 : one, b? two : two + 1);
	dfs(level+1, str, one, two);
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n+1);
	dfs(1, "", 0, 0);
	return 0;
}