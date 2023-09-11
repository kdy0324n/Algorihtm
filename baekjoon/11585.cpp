#include<bits/stdc++.h>
using namespace std;


vector<int>getpi(string str) {
	int n = str.size();
	vector<int>pi(n, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (str[i] != str[j] && j > 0)j = pi[j - 1];
		if (str[i] == str[j])pi[i] = ++j;
	}
	return pi;
}

int kmp(string par, string str) {
	int ans = 0;
	int n = par.size();
	int m = str.size();
	vector<int>pi = getpi(str);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (par[i] != str[j] && j > 0)j = pi[j - 1];
		if (par[i] == str[j]) {
			if (m - 1 == j) {
				ans++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string par = "", str = "";
	for (int i = 1; i <= n; i++) {
		char a; cin >> a;
		par += a;
	}
	string tmp = "";
	for (int i = 0; i < par.size()-1; i++) {
		tmp += par[i];
	}
	par += tmp;
	for (int i = 1; i <= n; i++) {
		char a; cin >> a;
		str += a;
	}
	int p = kmp(par, str);
	while (1) {
		if (p == 1)break;
		int g = gcd(n, p);
		if (g == 1)break;
		p /= g;
		n /= g;
	}
	cout << p << '/' << n;
	return 0;
}