#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>v;
int m;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;cin>>a;v.push_back(a);
    }
    sort(v.begin(),v.end());
    cin>>m;
    int s = 0,e=n-1;
    while(s<e){
        int t = v[s] + v[e];
        if(t==m){
            ans++,s++,e--;
        }
        else if(t<m){
            s++;
        }else{
            e--;
        }
    }
    cout<<ans;

    return 0;
}