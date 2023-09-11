#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[55][55];
int tmp[55][55];

int y11;
int x11;
int y22;
int x22;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void air_move() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0)continue;
            if (arr[i][j] == -1)continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny<1 || ny>n || nx<1 || nx>m)continue;
                if (arr[ny][nx] == -1)continue;
                tmp[ny][nx] += arr[i][j] / 5;
                cnt++;
            }
            arr[i][j] -= (arr[i][j] / 5 * cnt);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tmp[i][j]) {
                arr[i][j] += tmp[i][j]; tmp[i][j] = 0;
            }
        }
    }
}

void robot() {
    int y = y11;
    int x = x11;

    while (1) {
        int ty = y, tx = x;
        if (y == y11 && x == m)x--;
        else if (x == m)y++;
        else if (y == 1)x++;
        else if (x == 1)y--;
        else x--;

        if (arr[y][x] == -1) {
            arr[ty][tx] = 0; break;
        }
        if (arr[ty][tx] == -1) {
            arr[y][x] = 0; continue;
        }
        arr[ty][tx] = arr[y][x];
    }
    y = y22;
    x = x22;
    while (1) {
        int ty = y, tx = x;
        if (y == y22 && x == m)x--;
        else if (x == m)y--;
        else if (y == n)x++;
        else if (x == 1)y++;
        else x--;
        if (arr[y][x] == -1) {
            arr[ty][tx] = 0; break;
        }
        if (arr[ty][tx] == -1) {
            arr[y][x] = 0; continue;
        }
        arr[ty][tx] = arr[y][x];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    x22 = 0;

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1 && x22 == 0) {
                y11 = i;
                x11 = j;
                y22 = i + 1;
                x22 = j;
            }
        }
    }
    while (t--) {
        air_move();
        robot();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == -1)continue;
            ans += arr[i][j];
        }
    }
    cout << ans;
    return 0;
}