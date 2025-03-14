#include<bits/stdc++.h>
using namespace std;

int L, n;
using ll = long long;
vector<int>v, ans;//v = 집합 s 관리
vector<pair<ll, ll>>vv;//값,인덱스
ll inf = 2000e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L;
    for (int i = 1; i <= L; i++) {
        int a; cin >> a;
        v.push_back(a);
        vv.push_back({ 0,a });
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    cin >> n;
    for (int i = 1; i < v.size(); i++) {
        ll a = v[i - 1];
        ll b = v[i];
        if (b - a == 1)continue;
        if (b - a <= 220) {
            for (ll j = a + 1; j < b; j++) {
                ll val = (b - j) * (j - a) - 1;
                vv.push_back({ val,j });
            }
        }
        else {
            for (ll j = a + 1; j <= a + 100; j++) {
                ll val = (b - j) * (j - a) - 1;
                vv.push_back({ val,j });
            }
            for (ll j = b-100; j < b; j++) {
                ll val = (b - j) * (j - a) - 1;
                vv.push_back({ val,j });
            }
        }        
    } 
    for (int i = v.back() + 1; i <= v.back() + 110; i++) {
        vv.push_back({ inf,i });
    }
    sort(vv.begin(), vv.end());
    for (auto [a, b] : vv) {
        ans.push_back(b);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }



    return 0;
}