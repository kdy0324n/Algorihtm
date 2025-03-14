#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[110][110];
int chk[110][110];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int dfs(int y,int x){
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(arr[ny][nx]){
            chk[ny][nx]++;continue;
        }
        if(chk[ny][nx])continue;
        chk[ny][nx]=1;
        dfs(ny,nx);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    int a,b;
    for(int i=1;i<=n;i++){
        bool b = false;
        for(int j=1;j<=m;j++){
            if(arr[i][j]==0){
                b = true;
                a=i,b=j;break;
            }
        }
        if(b)break;
    }
    int ans=0;
    while(1){
        bool b = false;
        memset(chk,0,sizeof(chk));
        chk[a][b]=1;
        dfs(a,b);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(chk[i][j]>=2){
                    arr[i][j]=0;
                    b=true;
                }
            }
        }
        if(!b)break;
        ans++;
    }
    cout<<ans;
    return 0;
}