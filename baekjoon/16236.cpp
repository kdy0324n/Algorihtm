#include<bits/stdc++.h>
using namespace std;

int n;
int arr[22][22];
int chk[22][22];
int ans;
struct dd{
    int y,x,cost;
};
using pii = pair<int,int>;
int sharklevel = 2;
int eatcnt = 0;

queue<dd>q;
int dy[5] = {0,0,1,0,-1};
int dx[5] = {0,1,0,-1,0};

pii bfs(){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int cost = 1000;
    while(!q.empty()){
        int ty = q.front().y;
        int tx = q.front().x;
        int tcost = q.front().cost;
        q.pop();
        if(tcost<=cost){
            if(arr[ty][tx]<sharklevel&&arr[ty][tx]!=0){
                cost = min(cost,tcost);
                pq.push({ty,tx});
                continue;
            }
        }
        
        for(int i=1;i<=4;i++){
            int ny = ty + dy[i];
            int nx = tx + dx[i];
            int ncost = tcost + 1;
            if(ny>n||ny<1||nx>n||nx<1)continue;
            if(chk[ny][nx])continue;
            if(arr[ny][nx]>sharklevel)continue;
            q.push({ny,nx,ncost});
            chk[ny][nx]=1;
        }
    }
    if(cost!=1000)ans+=cost;
    if(pq.empty())return {0,0};
    return pq.top();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                q.push({i,j,0});
                chk[i][j] = 1;
                arr[i][j] = 0;
            }
        }
    }
    
    while(1){
        auto t = bfs();
        if(t.first==0&&t.second==0)break;
        arr[t.first][t.second]=0;
        eatcnt++;
        if(eatcnt==sharklevel)sharklevel++,eatcnt=0;

        memset(chk,0,sizeof(chk));        
        chk[t.first][t.second]=1;
        q.push({t.first,t.second,0});
    }
    cout<<ans;
    return 0;
}