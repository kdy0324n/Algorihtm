#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		int minVal = 2e9;
		int maxVal = -2e9;
		vector<int>V;
		long long hap = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			minVal = min(a, minVal);
			maxVal = max(a, maxVal);
			hap += a;
			V.push_back(a);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (V[i] == maxVal)cnt++;
		}
		if(cnt==1)maxVal--;		
		int v = maxVal - minVal;
		if (v > k)cout << "Jerry\n";
		else {
			if (hap % 2 == 0)cout << "Jerry\n";
			else cout << "Tom\n";
		}
	}



	return 0;
}