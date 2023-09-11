#include<bits/stdc++.h>
using namespace std;

int n,m,b;
int arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++)arr[i]=1;
    for(int i=1;i<=b;i++){
        int a;cin>>a;
        arr[a]=0;
    }
    int k = 0;
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        if(i<m)continue;
        k = max(k,arr[i]-arr[i-m]);
    }
    if(k>=m)cout<<0;
    else cout<<m-k;


    return 0;    
}