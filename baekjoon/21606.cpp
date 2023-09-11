#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200010];
int chk[200010];
int n;
string str;
int ans;
int ret;
void dfs(int cur){
    for(auto i:adj[cur]){
        if(chk[i])continue;
        if(str[i-1]=='0')chk[i]=1,dfs(i);
        else ret++;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>str;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(str[i-1]=='1'){
            for(auto j:adj[i]){
                ans+= str[j-1]=='1';
            }
        }
        else{
            if(chk[i])continue;
            ret = 0;
            chk[i]=1;
            dfs(i);
            ans+=ret*(ret-1);
        }
    }
    
    cout<<ans;


    return 0;
}