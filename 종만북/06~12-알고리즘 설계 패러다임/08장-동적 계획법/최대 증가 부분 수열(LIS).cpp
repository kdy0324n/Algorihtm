#include<iostream>
#include<algorithm>
using namespace std;

int arr[510];
int dp[510];

int n;
int d() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int a = 0;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                a = max(a, dp[j]);
            }
        }
        dp[i] += a;
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            dp[i] = 1;
        }
        cout << d() << '\n';
    }

    return 0;
}