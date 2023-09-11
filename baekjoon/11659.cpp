#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i] = arr[i-1]+a;
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<'\n';
    }

    return 0;
}