#include<bits/stdc++.h>
using namespace std;
long long arr[100001];
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	sort(arr, arr + num);
	int left = 0, right = num - 1;
	long long val, ans1 = arr[left], ans2 = arr[right], result = ans1 + ans2;
	while (left < right) {
		val = arr[left] + arr[right];
		if (abs(result) > abs(val)) {
			result = val;
			ans1 = arr[left];
			ans2 = arr[right];
		}
		if (val <= 0) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}