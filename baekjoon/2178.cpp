#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[110][110];
int chk[110][110];
struct dd{
    int y,x,cost;
};
int dy[5] = {0,0,1,0,-1};
int dx[5] = {0,1,0,-1,0};
queue<dd>q;
int bfs(){
    q.push({1,1,1});
    chk[1][1]=1;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cost = q.front().cost;
        q.pop();
        if(y==n&&x==m)return cost;
        for(int i=1;i<=4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<1||ny>n||nx<1||nx>m)continue;
            if(chk[ny][nx])continue;
            if(arr[ny][nx]==0)continue;
            chk[ny][nx]=1;
            q.push({ny,nx,cost+1});
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j+1] = str[j]-48;
        }
    }
    cout<<bfs();

    return 0;
}