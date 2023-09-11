#include <iostream>
using namespace std;

int n,m;
int arr[22];

int ans;

void dfs(int cur,int sum){
    if(cur>n){
        if(sum==m){
        ans++;
        }
        return;
    }
    
    dfs(cur+1,sum+arr[cur]);
    dfs(cur+1,sum);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dfs(1,0);
    if(m==0)ans--;
    cout<<ans;
    return 0;
}