#include<bits/stdc++.h>
using namespace std;

int n,m;
const int inf = 1e9;
int arr[110][110];
int par[110];
pair<int,int>chk[110];
int Find(int u){
    if(par[u]==0)return u;
    int res = Find(par[u]);
    par[u] = res;
    return res;
}

void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    if(u==v)return;
    par[u] = v;
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            arr[i][j]=inf;
        }
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int ans = 0;
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(par[i]==0){
            ans++;
            v.push_back(i);
            chk[i] = {i,inf};
        }
    }
    floyd();
    for(int i=1;i<=n;i++){
        int p = Find(i);
        int s = 0;
        for(int j=1;j<=n;j++){
            if(arr[i][j]==inf)continue;
            s=max(arr[i][j],s);
        }
        if(chk[p].second>s){
            chk[p]={i,s};
        }
    }
    cout<<ans<<'\n';
    vector<int>aa;
    for(auto i:v){
        aa.push_back(chk[i].first);
    }
    sort(aa.begin(),aa.end());
    for(auto i:aa){
        cout<<i<<'\n';
    }
    return 0;
}
// ㅋㅋㅋㅋㅋ 진짜 문제를 잘읽자 개새기들이 이런 함정을 숨겨놓을지 모른다.
// 플로이드 와샬로 구한 각 정점에서 다른 정점들로 가는 합의 최소값이 대표값이 되는 것이아니라 다른 정점으로 가는 최대값중에서 최소값이 되는 
//정점이 대표값이 된다. 이런 ㅅㅂ람들