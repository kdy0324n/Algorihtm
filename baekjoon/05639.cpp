#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10010];


void dfs(int s, int e) {
	if (s > e) return;

	int root = arr[s];
	int mid = e+1;
	for (int i = s + 1; i <= e; i++) {
		if (root < arr[i]) {
			mid = i; break;
		}
	}
	dfs(s+1, mid - 1);
	dfs(mid, e);
	cout << root << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int i = 1;
	while (cin >> a) {
		arr[i] = a;
		i++;
	}
	n = i - 1;
	dfs(1, n);
	return 0;
}