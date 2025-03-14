/*#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int t, n, m;
int A[1010], B[1010];
vector<int>a, b;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = i; j <= n; j++) {
            tmp += A[j];
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= m; i++) {
        int tmp = 0;
        for (int j = i; j <= m; j++) {
            tmp += B[j];
            auto k = lower_bound(a.begin(), a.end(), t - tmp)-a.begin();
            auto k2 = upper_bound(a.begin(), a.end(), t - tmp)-a.begin();
            ans += k2 - k;
        }
    }
    cout << ans;
    return 0;
}*/ //정석

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int t, n, m;
int A[1010], B[1010];
vector<int>a, b;
map<int, ll>Map;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = i; j <= n; j++) {
            tmp += A[j];
            Map[tmp]++;
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= m; i++) {
        int tmp = 0;
        for (int j = i; j <= m; j++) {
            tmp += B[j];
            auto k = lower_bound(a.begin(), a.end(), t - tmp);
            if (*k + tmp == t) {
                ans += Map[*k];
            }
        }
    }
    cout << ans;
    return 0;
}//숫자의 개수를 맵을 사용하여 나타냄. 그러나 시간복잡도는 조금더 걸림