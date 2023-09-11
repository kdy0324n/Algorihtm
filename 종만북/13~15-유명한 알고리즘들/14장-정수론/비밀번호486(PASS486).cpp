/*#include<bits/stdc++.h>
using namespace std;

const int N=10000000;
int minFactor[10000010];

void era() {

	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= N; i++)
		minFactor[i] = i;
	int sqn = int(sqrt(N));
	for (int i = 2; i <= sqn; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= N; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

bool factor(int t,int n) {
	map<int, int>Map;
	set<int>key;
	while (t > 1) {
		Map[minFactor[t]]++;
		key.insert(minFactor[t]);
		t /= minFactor[t];
	}
	int ans = 1;
	for (auto i : key) {
		ans *= (Map[i]+1);
	}
	if (ans == n)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	era();
	while (t--) {
		int n;
		int ans = 0;
		cin >> n;
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			if (factor(i,n))ans++;
		}		
		cout << ans << '\n';
	}

	return 0;
}*///처음 시도 해본것
#include<iostream>
#include<cmath>
using namespace std;

const int N=10000000;
int minFactor[N+1];//i의 가장 작은 소인수
int minFactorPower[N + 1];//i의 소인수 분해에는 minFactor[i]의 몇승이 포함되어 있는가
int factors[N + 1];//i가 가진 약수의 수

void era() {
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= N; i++)
		minFactor[i] = i;
	int sqn = int(sqrt(N));
	for (int i = 2; i <= sqn; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= N; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

void factor() {
	factors[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (minFactor[i] == i) {
			minFactorPower[i] = 1;
			factors[i] = 2;
		}
		else {
			int p = minFactor[i];
			int m = i / p;
			if (p != minFactor[m])
				minFactorPower[i] = 1;
			else
				minFactorPower[i] = minFactorPower[m] + 1;
			int a = minFactorPower[i];
			factors[i] = (factors[m] / a) * (a + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	era();
	factor();
	while (t--) {
		int n;
		int ans = 0;
		cin >> n;
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			if (factors[i] == n)ans++;
		}		
		cout << ans << '\n';
	}

	return 0;
}