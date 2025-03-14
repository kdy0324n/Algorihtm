#include<iostream>
using namespace std;

int n;
int inorder[100010];
int postorder[100010];
int m[100010];

void preorder(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e)return;
	int rootidx = m[postorder[post_e]];
	int l = rootidx - in_s;
	int r = in_e - rootidx;
	cout << inorder[rootidx]<<' ';

	preorder(in_s, in_s + l - 1, post_s, post_s + l - 1);
	preorder(rootidx + 1, in_e, post_s + l, post_e - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		m[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}
	preorder(1, n, 1, n);

	return 0;
}