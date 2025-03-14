#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[1000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    string str;
    cin>>str;
    int ans = 0;
    for(int i=0;i<str.size()-2;i++){
        if(str[i]=='O')continue;
        int k=0;
        while(str[i+1]=='O'&&str[i+2]=='I'){
            k++;
            if(k>=n){
                ans++;
                k--;
            }
            i+=2;
        }        
    }
    cout<<ans;


    return 0;
}