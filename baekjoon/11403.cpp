#include<bits/stdc++.h>
using namespace std;

int n;
int arr[110][110];
int ans[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k]&&arr[k][j]){
                    ans[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}