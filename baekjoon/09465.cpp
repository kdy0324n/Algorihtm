#include<bits/stdc++.h>
using namespace std;

int t;
int dp[3][100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--){
        int n;cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=2;i++){
            for(int j=2;j<=n+1;j++){
                cin>>dp[i][j];
            }
        }
        for(int j=2;j<=n+1;j++){
            dp[1][j] += max(dp[2][j-1],dp[2][j-2]);
            dp[2][j] +=max(dp[1][j-1],dp[1][j-2]);
        }
        cout<<max(dp[1][n+1],dp[2][n+1])<<'\n';
    }


    return 0;
}