#include<bits/stdc++.h>
using namespace std;

int dp[34][34];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;cin>>t;

    for(int i=1;i<=30;i++){
        dp[1][i]=i;
    }
    for(int i=2;i<=30;i++){
        for(int j=1;j<=30;j++){
            int a = 0;
            for(int k=1;k<j;k++){
                a+=dp[i-1][k];
            }
            dp[i][j] = a;
        }
    }

    while(t--){
        int a,b;cin>>a>>b;
        cout<<dp[a][b]<<'\n';

    }


    return 0;
}