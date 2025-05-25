#include<bits/stdc++.h>
using namespace std;

int arr[110];
int ans[110];

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	int t; cin >> t;
	while (t--) {
		bool flag = false;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		
		for (int i = 1; i <= n; i++) {
			
			int k = 0;
			for (int j = 1; j <= n; j++) {
				if (j == i)continue;
				if (k == 0) {
					k = gcd(arr[j], arr[j]); continue;
				}
				k = gcd(k, arr[j]);
			}
			if (k != arr[i]) {
				flag = true;
				cout << "yes\n";
				for (int j = 1; j <= n; j++) {
					if (j == i) {
						cout << 2 << ' '; continue;
					}
					cout << 1 << ' ';
				}
				cout << '\n';
				break;
			}
		}
		if (!flag)cout << "no\n";
	}


	return 0;
}