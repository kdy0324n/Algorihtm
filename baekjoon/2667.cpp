#include<bits/stdc++.h>
using namespace std;

int n;
int arr[30][30];
int chk[30][30];

vector<int>ans;
int dy[5]={0,0,1,0,-1};
int dx[5]={0,1,0,-1,0};

int dfs(int y,int x){
    int ret = 1;
    for(int i=1;i<=4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<1||ny>n||nx<1||nx>n)continue;
        if(chk[ny][nx])continue;
        if(arr[ny][nx]==0)continue;
        chk[ny][nx]=1;
        ret += dfs(ny,nx);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        string str; cin>>str;
        for(int j=0;j<str.size();j++){
            arr[i][j+1] = str[j]-48;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==0)continue;
            if(chk[i][j])continue;
            chk[i][j]=1;
            ans.push_back(dfs(i,j));
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(auto i: ans){
        cout<<i<<'\n';
    }
    return 0;
}