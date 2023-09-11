#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int arr[20010];

int divide(int l, int r) {
	if (l == r) {
		return arr[l];
	}
	int mid = (l + r) / 2;
	int ret = max(divide(l, mid), divide(mid + 1, r));
	
	int s = mid, e = mid + 1;
	int h = min(arr[s], arr[e]);
	ret = max(ret, h * 2);
	while (l < s || e < r) {
		if (e<r&&(arr[s - 1] < arr[e + 1] || l==s)) {
			e++;
			h = min(h, arr[e]);
		}
		else {
			s--;
			h = min(h, arr[s]);
		}
		ret = max(ret, h * (e - s + 1));
	}	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	vector<int>v;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		v.push_back(divide(1, n));
	}
	for (auto i : v) {
		cout << i << '\n';
	}

	return 0;
}