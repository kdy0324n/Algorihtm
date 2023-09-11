#include<bits/stdc++.h>
using namespace std;

int n,m;

using pii = pair<int,int>;
pii ladder[16],snake[16];
int chk[110];
queue<pii>q;//값,횟수

int fuc(int val){
    for(int i=1;i<=n;i++){
        if(ladder[i].first==val)return ladder[i].second;
    }
    for(int i=1;i<=m;i++){
        if(snake[i].first==val)return snake[i].second;
    }
    return val;
}

int bfs(){
    q.push({1,0});
    chk[1]=1;
    while(!q.empty()){
        int t = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(t==100)return cnt;
        for(int i=1;i<=6;i++){
            int nt = t + i;            
            if(nt<1||nt>100)continue;
            if(chk[nt])continue;
            chk[nt]=1;
            int ntt = fuc(nt);
            if(ntt!=nt){
                if(chk[ntt])continue;
                chk[ntt]=1;
                q.push({ntt,cnt+1});
            }
            else{
                q.push({nt,cnt+1});
            }            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ladder[i].first>>ladder[i].second;
    }
    for(int j=1;j<=m;j++){
        cin>>snake[j].first>>snake[j].second;
    }
    cout<<bfs();

    return 0;
}