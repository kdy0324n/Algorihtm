#include<iostream>
using namespace std;


int n;
int pre[1010];
int in[1010];
int idx[1010];

void post(int pre_s, int pre_e, int in_s, int in_e) {
	if (pre_s > pre_e || in_s > in_e)return;

	int root = pre[pre_s];
	int rootidx = idx[root];
	int leftsize = rootidx - in_s;
	int rightsize =  in_e - rootidx;

	post(pre_s + 1, pre_s + leftsize, in_s, rootidx - 1);
	post(pre_e - rightsize + 1, pre_e, rootidx + 1, in_e);
	cout << root << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> pre[i];
		for (int i = 1; i <= n; i++) {
			cin >> in[i];
			idx[in[i]] = i;
		}
		post(1, n, 1, n);
		cout << '\n';
	}


	return 0;
}