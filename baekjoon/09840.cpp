#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
string arr[32];
struct dd {
    int y, x, chk;
};

int dp[32][32][1 << 10];
queue<dd>q;
int sy, sx, ey, ex;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

map<pii, int>Map;
int idx = 0;


void bfs() {
    while (!q.empty()) {
        auto t = q.front();
        int cost = dp[t.y][t.x][t.chk];
        q.pop();

        if (t.y == ey && t.x == ex && t.chk == (1 << idx) - 1) {
            cout << cost;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = t.y + dy[i];
            int nx = t.x + dx[i];
            int ncost = cost + 1;
            if (ny < 0 || n <= ny || nx < 0 || n <= nx)continue;
            if (arr[ny][nx] == 'X')continue;
            int nchk = arr[ny][nx] == 'F' ? t.chk | 1 << Map[{ny, nx}] : t.chk;
            if (dp[ny][nx][nchk] != -1)continue;

            q.push({ ny,nx,nchk });
            dp[ny][nx][nchk] = ncost;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'S') {
                sy = i, sx = j;
            }
            if (arr[i][j] == 'B') {
                ey = i, ex = j;
            }
            if (arr[i][j] == 'F') {
                Map[{i, j}] = idx++;
            }
        }
    }

    dp[sy][sx][0] = 0;
    q.push({ sy,sx,0 });
    bfs();

    return 0;
}