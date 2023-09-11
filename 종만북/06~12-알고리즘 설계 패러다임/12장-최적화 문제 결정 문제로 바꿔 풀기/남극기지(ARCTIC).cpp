#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int n;
using pdd = pair<double, double>;
pdd arr[110];
double dist[110][110];
int chk[110];
bool decision(double d) {
	queue<int>q;
	memset(chk, 0, sizeof(chk));
	q.push(1);
	chk[1] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (i == t)continue;
			if (chk[i])continue;
			if (dist[t][i] > d)continue;
			q.push(i);
			chk[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)if (!chk[i])return false;
	return true;
}


double solve() {
	double l=0, r=2000;
	for(int i=1;i<=100;i++){
		double mid = (l + r)/2;
		//mid *= 100;
		//mid = round(mid);
		//mid /= 100;
		if (decision(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	return l;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				double tmp = sqrt(pow((arr[i].first - arr[j].first),2) + pow((arr[i].second - arr[j].second),2));
				dist[i][j] = tmp;
			}
		}
		double ans = solve();
		cout << ans << '\n';
	}

	return 0;
}

/* 최소 스패닝 트리 풀이 
#include<bits/stdc++.h>
using namespace std;

int n;

using pdd = pair<double, double>;
using pdi = pair<double, int>;//거리, 정점
double dist[110][110];
pdd arr[110];
priority_queue<pdi, vector<pdi>, greater<pdi>>pq;
int chk[110];

double solve() {
	memset(chk, 0, sizeof(chk));
	double ret = 0;
	pq.push({-1,1});
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		if (chk[t.second])continue;
		chk[t.second] = 1;
		ret = max(ret, t.first);
		for (int i = 1; i <= n; i++) {
			if (i == t.second)continue;
			if (chk[i])continue;
			pq.push({ dist[t.second][i],i });
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)dist[i][j] = -1;
				else {
					dist[i][j] = sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
				}
			}
		}
		cout<<solve()<<'\n';
	}

	return 0;
}
*/