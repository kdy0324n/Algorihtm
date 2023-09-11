#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
int Start,End;
int n,m;
vector<pii>adj[10010];
vector<pii>counter_adj[10010];
int inde[10010];
ll w[10010];
ll maxval;
void kahn(){
    vector<int>tp;
    tp.push_back(End);
    for(int i=0;i<tp.size();i++){
        int node = tp[i];
        for(auto&j:counter_adj[node]){
            inde[j.first]--;
            w[j.first] = max(w[j.first],j.second + w[node]);
            if(inde[j.first]==0){
                tp.push_back(j.first);
            }
        }
    }
}
queue<pii>q;//노드번호,비용
int chk[10010];
set<pair<int,ll>>s;
void bfs(){
    
    q.push({Start,0});
    chk[Start]=1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        for(auto&i:adj[t.first]){
            int n_node = i.first;
            ll n_cost = i.second + t.second;
            if(n_cost + w[n_node] == maxval){
                if(s.insert({t.first,n_node}).second)
                    q.push({n_node,n_cost});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        counter_adj[b].push_back({a,c});
        inde[a]++;
    }
    cin>>Start>>End;
    kahn();   
    maxval = w[Start];
    bfs();
    cout<<maxval<<'\n'<<s.size();
    
    return 0;
}