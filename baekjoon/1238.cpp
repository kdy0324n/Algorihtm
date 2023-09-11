#include<bits/stdc++.h>
using namespace std;

int n,m,x;
int dist[1010];
int x_dist[1010];
using pii = pair<int,int>;
vector<pii>adj[1010];
vector<pii>adj2[1010];
int inf = 1e9;
void dijkstra(int u,int type){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i=1;i<=n;i++)dist[i]=inf;
    pq.push({0,u});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        if(dist[t.second]!=inf)continue;
        dist[t.second] = t.first;
        if(type==1){
            for(auto &j:adj[t.second]){
                if(dist[j.first]==inf){
                    pq.push({t.first + j.second,j.first});
                }
            }
        }
        else{
            for(auto &j:adj2[t.second]){
                if(dist[j.first]==inf){
                    pq.push({t.first + j.second,j.first});
                }
            }
        }
    }
}
int ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }
    dijkstra(x,1);
    for(int i=1;i<=n;i++)x_dist[i]=dist[i];
    dijkstra(x,2);
    for(int i=1;i<=n;i++){
        ans = max(ans,dist[i]+x_dist[i]);
    }
    cout<<ans;
    return 0;
}

//풀이 - 1. 반대로 돌아오는 거리를 구해서 n개의 도시를 돌면서 일일이 구하면 n * mlogm만에 구할수 있다.
//     - 2. 단방향성 간선의 반대 방향성의 간선들을 저장해주고 각 시작점에서 한번씩만 다익스트라를 돌리고 그 값들을 저장하면 n + 2*mlogm만에 구할수 있다.