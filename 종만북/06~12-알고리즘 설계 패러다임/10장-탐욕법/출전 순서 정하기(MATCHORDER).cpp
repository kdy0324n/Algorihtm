#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int n;
int chk[110];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		cin >> n;
		int ans = n;
		vector<int>rusia;
		vector<int>korea;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a; rusia.push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			int a; cin >> a; korea.push_back(a);
		}
		sort(korea.begin(), korea.end());
		
		for (int i = 0; i < n; i++) {
			bool b = false;
			for (int j = 0; j < n; j++) {
				if (chk[j])continue;
				if (korea[j] >= rusia[i]) {
					chk[j] = 1;
					b = true;
					break;
				}
			}
			if (b)continue;
			for (int j = 0; j < n; j++) {
				if (chk[j])continue;
				chk[j] = 1;
				ans--;
				break;
			}
		}
		cout << ans<<'\n';
	}



	return 0;
}