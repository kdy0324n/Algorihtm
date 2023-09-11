#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>d,b;
vector<int>adj[1010];
int chk[1010];

void dfs(int cur){
    for(int i=0;i<adj[cur].size();i++){
        int t = adj[cur][i];
        if(chk[t])continue;
        chk[t]=1;
        d.push_back(t);
        dfs(t);
    }
}
queue<int>q;
void bfs(){
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<adj[cur].size();i++){
            int t = adj[cur][i];
            if(chk[t])continue;
            chk[t]=1;
            b.push_back(t);
            q.push(t);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    chk[t]=1;
    d.push_back(t);
    dfs(t);

    memset(chk,0,sizeof(chk));

    chk[t]=1;
    b.push_back(t);
    q.push(t);
    bfs();
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<' ';
    }
    return 0;
}