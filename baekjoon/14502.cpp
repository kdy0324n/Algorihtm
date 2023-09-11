#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[11][11];
int chk[11][11];
using pii = pair<int,int>;
queue<pii>q;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int bfs(){
    int ret=0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<1||ny>n||nx<1||nx>m)continue;
            if(chk[ny][nx])continue;
            if(arr[ny][nx])continue;
            chk[ny][nx]=1;
            q.push({ny,nx});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j])continue;
            if(chk[i][j])continue;
            ret++;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    vector<pii>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2)v.push_back({i,j});
        }
    }
    int ans = 0;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            if(arr[a][b])continue;
            arr[a][b]=1;
            for(int c=1;c<=n;c++){
                for(int d=1;d<=m;d++){
                    if(arr[c][d])continue;
                    arr[c][d]=1;
                    for(int e=1;e<=n;e++){
                        for(int f=1;f<=m;f++){
                            if(arr[e][f])continue;
                            arr[e][f]=1;
                            memset(chk,0,sizeof(chk));
                            for(auto[i,j]:v)q.push({i,j}),chk[i][j]=1;
                            ans = max(bfs(),ans);
                            arr[e][f]=0;                            
                        }
                    }
                    arr[c][d]=0;
                }
            }
            arr[a][b]=0;
        }
    }
    cout<<ans;
    return 0;
}