#include<bits/stdc++.h>
using namespace std;

int n, m;
int broken[11];
int ans = 1e9;

bool check(int cur) {
    if (cur == 0) {
        if (!broken[0])return true;
        return false;
    }
    else {
        while (cur) {
            int tmp = cur % 10;
            if (broken[tmp])return false;
            cur /= 10;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ans = min(ans, abs(n - 100));
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        broken[a] = 1;
    }
    for (int i = 0; i <= 1000000; i++) {
        string str;
        if (check(i)) {
            str = to_string(i);
            int tmp = abs(n - i) + str.size();
            ans = min(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}