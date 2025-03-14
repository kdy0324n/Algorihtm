#include<iostream>
using namespace std;


int arr[4010][8000];

void pp(int y, int x) {
	arr[y][x] = 1;
	arr[y + 1][x - 1] = 1;
	arr[y + 1][x + 1] = 1;

	arr[y + 2][x - 2] = 1;
	arr[y + 2][x - 1] = 1;
	arr[y + 2][x] = 1;
	arr[y + 2][x + 1]=1;
	arr[y + 2][x + 2]=1;
}

void dfs(int n,int y,int x) {
	if (n == 3) {
		pp(y, x);
		return;
	}
	dfs(n/2, y, x);
	dfs(n / 2, y + n / 2, x + n / 2);
	dfs(n / 2, y + n / 2, x - n / 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dfs(n,1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n * 2; j++) {
			if (arr[i][j])cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
	return 0;
}