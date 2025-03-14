#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[33];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=30;i+=2){
        int idx = i;
        dp[idx] +=dp[idx-2] * dp[2];
        idx-=4;
        for(int j=idx;j>=0;j-=2){
            dp[i]+=dp[j] * 2;
        }
    }
    cout<<dp[n];

    return 0;
}