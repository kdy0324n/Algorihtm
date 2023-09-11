#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

int t,n,m,w;
using tiii = tuple<int,int,int>;
int inf = 1e9;
bool bellman(vector<tiii>adj){
    int dist[510];
    for(int i=1;i<=n;i++)dist[i]=inf;
    dist[1]=0;
    for(int i=1;i<n;i++){
        for(auto[a,b,c]:adj){
            if(dist[b]>dist[a]+c)dist[b]=dist[a]+c;
        }
    }
    for(auto[a,b,c]:adj){
        if(dist[b]>dist[a]+c)return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m>>w;
        vector<tiii>adj;
        for(int i=1;i<=m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj.push_back({a,b,c});
            adj.push_back({b,a,c});
        }
        for(int i=1;i<=w;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj.push_back({a,b,-c});
        }
        if(bellman(adj))cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}