#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>>adj[110];
int dp[110];
int chk[110];
int inde[110];
vector<int>v;
void kahn(){
    vector<int>tp;
    tp.push_back(n);
    dp[n]=1;
    for(int i=0;i<tp.size();i++){
        int cur = tp[i];
        for(auto[a,b]:adj[cur]){
            inde[a]--;
            dp[a] += dp[cur] * b;
            if(inde[a]==0)tp.push_back(a);
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
        chk[a]=1;
        adj[a].push_back({b,c});
        inde[b]++;
    }
    kahn();
    for(int i=1;i<=n;i++){
        if(chk[i])continue;
        cout<<i<<' '<<dp[i]<<'\n';
    }
    return 0;
}