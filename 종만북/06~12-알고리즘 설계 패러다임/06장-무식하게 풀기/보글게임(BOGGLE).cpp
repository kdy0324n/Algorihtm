#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

char arr[6][6];
int chk[6][6][11];
int n = 5;
bool flag = false;
int dy[] = { -1,0,1,1,1,0,-1,-1 };
int dx[] = { 1,1,1,0,-1,-1,-1,0 };
void rec(int y, int x, string a, string b) {
    if (a.size() >= b.size()) {
        flag = true;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<1 || ny>n || nx<1 || nx>n)continue;
        if (chk[ny][nx][a.size()])continue;
        if (arr[ny][nx] == b[a.size()]) {
            chk[ny][nx][a.size()] = 1;
            rec(ny, nx, a + b[a.size()], b);
        }
        if(flag)return;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            for (int j = 1; j <= n; j++) {
                arr[i][j] = str[j - 1];
            }
        }
        int m;
        cin >> m;
        while (m--) {
            flag = false;
            memset(chk, 0, sizeof(chk));
            string str;
            cin >> str;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (arr[i][j] == str[0]) {
                        string s = "";
                        s += str[0];
                        rec(i, j, s, str);
                    }
                    if (flag)break;
                }
                if (flag)break;
            }
            cout << str << ' ';
            if (flag)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }

    return 0;
}
