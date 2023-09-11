#include<bits/stdc++.h>
using namespace std;

string ans;
int arr[110][110];
int n;

bool check(int up,int down,int left,int right){
    int a = arr[up][left];
    for(int i=up;i<=down;i++){
        for(int j=left;j<=right;j++){
            if(arr[i][j]!=a)return false;
        }
    }
    return true;
}

void dfs(int up,int down,int left,int right){
    if(check(up,down,left,right)){
        if(arr[up][left]==1){
            ans+="1";
        }else{
            ans+="0";
        }
        return;
    }
    int y_mid = (up+down)/2;
    int x_mid = (left+right)/2;
    ans+="(";
    dfs(up,y_mid,left,x_mid);
   

    
    dfs(up,y_mid,x_mid+1,right);
    

    
    dfs(y_mid+1,down,left,x_mid);
    

    
    dfs(y_mid+1,down,x_mid+1,right);
    ans+=")";    


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        string str;cin>>str;
        for(int j=0;j<n;j++){
            arr[i][j+1] = str[j]-48;
        }
    }
    dfs(1,n,1,n);
    cout<<ans;
    return 0;
}