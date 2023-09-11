#include<bits/stdc++.h>
using namespace std;

int dp[50010];
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=50000;i++)dp[i]=100;
    for(int i=1;i<=300;i++){
        if(i*i>50000)break;
        v.push_back(i*i);
        dp[i*i]=1;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=50000;i++){
        for(auto j:v){
            int idx = i+j;
            if(idx>50000)break;
            dp[idx] = min(dp[i]+1,dp[idx]);
        }
    }
    cout<<dp[n];


    return 0;
}