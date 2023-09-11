#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
priority_queue<pii>max_q;
priority_queue<pii, vector<pii>, greater<pii>>min_q;
int chk[1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(chk, 0, sizeof(chk));
        for (int i = 1; i <= n; i++) {
            int a;
            char s;
            cin >> s >> a;
            if (s == 'I') {
                max_q.push({ a,i });
                min_q.push({ a,i });
                chk[i] = 1;
            }
            else {
                if (a == 1) {
                    while (!max_q.empty()) {
                        auto t = max_q.top();
                        max_q.pop();
                        if (chk[t.second]) {
                            chk[t.second] = 0;
                            break;
                        }
                    }
                }
                else {
                    while (!min_q.empty()) {
                        auto t = min_q.top();
                        min_q.pop();
                        if (chk[t.second]) {
                            chk[t.second] = 0;
                            break;
                        }
                    }
                }
            }
        }
        bool b = false;
        while (1) {
            if (max_q.empty()) {
                b = true; break;
            }
            auto t = max_q.top();
            if (chk[t.second]) {
                cout << t.first << ' ';
                break;
            }
            max_q.pop();
        }
        if (b)cout << "EMPTY" << '\n';
        else {
            while (1) {
                auto t = min_q.top();
                if (chk[t.second]) {
                    cout << t.first << '\n';
                    break;
                }
                min_q.pop();
            }
        }
        while (!max_q.empty())max_q.pop();
        while (!min_q.empty())min_q.pop();
    }

    return 0;
}