#include<bits/stdc++.h>
using namespace std;
 
int N;
int arr[2200][2200];
//[0]:-1종이 개수, [1]:0종이 개수, [2]:1종이 개수
int answer[3];
 
//모두 같은 숫자인지 판단
bool check(int x, int y, int n) {
    
    int check = arr[x][y];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[x + i][y + j] != check) {
                return false;
            }
        }
    }
 
    return true;
}
 
void dfs(int x, int y, int n) {
 
    //종이가 모두 같은 숫자일 경우 -> 해당 종이 갯수 + 1, 종료
    if (check(x, y, n)) {
        int paperNum = arr[x][y];
        answer[paperNum + 1]++;
        return;
    }
 
    int div = n / 3;
 
    //9개로 나누어서 분할 정복
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dfs(x + div * i, y + div * j, div);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
 
    //해법
    /*
    9개로 나누어서 분할 정복
    */
    dfs(0, 0, N);
 
    //출력
    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
    }
 
    //종료
    return 0;
}
