#include<iostream>
#include<algorithm>
using namespace std;

int m = 1e9+7;
int dp[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=100;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i]%=m;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        cout<<dp[a]<<'\n';
    }

    return 0;
}