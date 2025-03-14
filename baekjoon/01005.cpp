#include<bits/stdc++.h>
using namespace std;

using tiii = tuple<int,int,int>;
using pii = pair<int,int>;
using ll = long long;

int indegree[1010];
ll ans[1010],w[1010];

void kahn(int n,vector<int>adj[1010]){
    vector<int>tp;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){tp.push_back(i);ans[i]=w[i];}
    }
    for(int i=0;i<tp.size();i++){
        ll t = ans[tp[i]];
        for(auto&j:adj[tp[i]]){
            indegree[j]--;
            ans[j] = max(ans[j], t + w[j]);
            if(indegree[j]==0){
                tp.push_back(j);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        vector<int>adj[1010];
        memset(indegree,0,sizeof(indegree));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        for(int i=1;i<=k;i++){
            int a,b;
            cin>>a>>b;
            adj[a].emplace_back(b);
            indegree[b]++;
        }
        kahn(n,adj);
        int z;cin>>z;
        cout<<ans[z]<<'\n';
    }


    return 0;
}