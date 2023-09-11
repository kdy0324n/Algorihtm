#include<bits/stdc++.h>
using namespace std;

int n;
int arr1[110][110],arr2[110][110];
int chk[110][110];

int dy[5]={0,0,1,0,-1};
int dx[5]={0,1,0,-1,0};

void dfs1(int y,int x,int type){
    for(int i=1;i<=4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<1||ny>n||nx<1||nx>n)continue;
        if(chk[ny][nx])continue;
        if(arr1[ny][nx]!=type)continue;
        chk[ny][nx]=1;
        dfs1(ny,nx,type);
    }
}
void dfs2(int y,int x,int type){
    for(int i=1;i<=4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<1||ny>n||nx<1||nx>n)continue;
        if(chk[ny][nx])continue;
        if(arr2[ny][nx]!=type)continue;
        chk[ny][nx]=1;
        dfs2(ny,nx,type);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;cin>>str;
        for(int j=0;j<n;j++){
            if(str[j]=='R'){
                arr1[i][j+1] = 1;
                arr2[i][j+1]=1;
            }
            else if(str[j]=='G'){
                arr1[i][j+1] = 1;
                arr2[i][j+1]=2;
            }
            else{
                arr1[i][j+1]=3;
                arr2[i][j+1]=3;
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(chk[i][j])continue;
            if(!arr1[i][j])continue;
            chk[i][j]=1;
            dfs1(i,j,arr1[i][j]);
            ans1++;
        }
    }
    memset(chk,0,sizeof(chk));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(chk[i][j])continue;
            if(!arr2[i][j])continue;
            chk[i][j]=1;
            dfs2(i,j,arr2[i][j]);
            ans2++;
        }
    }
    cout<<ans2<<' '<<ans1;
    return 0;
}