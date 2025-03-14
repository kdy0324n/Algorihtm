#include<bits/stdc++.h>
using namespace std;

int n;
int max_dp[3][5];
int min_dp[3][5];
int inf = 1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    
    min_dp[2][0] = min_dp[2][4]=inf;
    min_dp[1][0] = min_dp[1][4]=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int a;cin>>a;
            max_dp[2][j]=min_dp[2][j]=a;
            max_dp[2][j]+=max(max_dp[1][j-1],max(max_dp[1][j],max_dp[1][j+1]));
            min_dp[2][j]+=min(min_dp[1][j-1],min(min_dp[1][j],min_dp[1][j+1]));
        }
        for(int i=0;i<5;i++){
            max_dp[1][i] = max_dp[2][i];
            min_dp[1][i] = min_dp[2][i];
        }
    }
    int ans[2]={0,inf};
    for(int i=1;i<=3;i++){
        ans[0] = max(ans[0],max_dp[2][i]);
        ans[1] = min(ans[1],min_dp[2][i]);
    }
    cout<<ans[0]<<' '<<ans[1];


    return 0;
}