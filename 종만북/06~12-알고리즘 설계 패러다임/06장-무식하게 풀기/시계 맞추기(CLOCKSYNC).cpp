#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int clk[16];
int ans = 1e9;
vector<vector<int>>swtch({
    vector<int>({ 0, 1, 2 }),
    vector<int>({ 3, 7, 9, 11 }),
    vector<int>({ 4, 10, 14, 15 }),
    vector<int>({ 0, 4, 5, 6, 7 }),
    vector<int>({ 6, 7, 8, 10, 12 }),
    vector<int>({ 0, 2, 14, 15 }),
    vector<int>({ 3, 14, 15 }),
    vector<int>({ 4, 5, 7, 14, 15 }),
    vector<int>({ 1, 2, 3, 4, 5 }),
    vector<int>({ 3, 4, 5, 9, 13 })
});

bool check() {
    for (int i = 0;i< 16; i++) {
        if (clk[i] % 12 != 0)return false;
    }
    return true;
}

void push(int cur, int val) {
    for (auto i:swtch[cur]) {
        clk[i] += val;
    }
}

void dfs(int cur, int cnt) {
    if (cur >= 10) {
        if (check()) {
            ans = min(ans, cnt);
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        push(cur, i * 3);
        dfs(cur + 1, cnt + i);
        push(cur, -(i * 3));
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        ans = 1e9;
        for (int i = 0; i < 16; i++) {
            cin >> clk[i];
        }
        dfs(0, 0);
        if (ans == 1e9)cout << -1 << '\n';
        else cout << ans << '\n';
    }


	return 0;
}