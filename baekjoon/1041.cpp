#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[7];
using pii = pair<int, int>;
int chk[7][7];
long long one=100, two=200, three=400;
void f() {

	for (int i = 1; i <= 6; i++) {
		one = min(one, arr[i]);
		for (int j = 1; j <= 6; j++) {
			if (i == j)continue;
			if (chk[i][j])continue;
			two = min(two, arr[i] + arr[j]);
			for (int k = 1; k <= 6; k++) {
				if (i == k || j == k)continue;
				if (chk[i][j])continue;
				if (chk[j][k])continue;
				if (chk[i][k])continue;
				three = min(three, arr[i] + arr[j] + arr[k]);
			}
		}
	}

	
}
long long ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	chk[1][6] = chk[6][1] = 1;
	chk[2][5] = chk[5][2] = 1;
	chk[3][4] = chk[4][3] = 1;

	cin >> n;
	for (int i = 1; i <= 6; i++) {
		cin >> arr[i];
	}
	f();

	if (n == 1) {// n이 1일때 정육면체 1개만 쓰므로 6개면중에서 작은순으로 5개 고르기
		sort(arr+1, arr + 7);
		for (int i = 1; i < 6; i++)ans += arr[i];
	}
	else if (n == 2)ans = (three * 4) + (two * 4);//n이 2일때 정육면체 8개를 쓰는데 면이 하나만 노출되는 부분이 없다.
	else {//모서리(면3개 노출) * 4
		  // 기둥(면 2개 노출)*4 + 꼭짓점 제외하고 윗변 모서리(면 2개 노출) *4
		  // 천장에서 모서리 제외한 부분 + 아래 모서리만 빼고 나머지 모서리를 배제한 수 * 4
		ans += three * 4;
		ans += ((n-1)*4 + (n-2)*4) * two;
		ans += one * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
	}
	cout << ans;
	return 0;
}