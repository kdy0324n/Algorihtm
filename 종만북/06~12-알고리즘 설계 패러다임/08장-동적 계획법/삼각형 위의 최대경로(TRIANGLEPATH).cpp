#include<iostream>
#include<algorithm>
using namespace std;

int arr[110][110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> arr[1][1];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int a;
                cin >> a;
                arr[i][j] = max(arr[i - 1][j], arr[i-1][j-1]) + a;
                ans = max(ans, arr[i][j]);
            }
        }
        cout << ans << '\n';
    }


    return 0;
}