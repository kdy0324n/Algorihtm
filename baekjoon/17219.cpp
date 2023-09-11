#include<bits/stdc++.h>
using namespace std;

map<string,string>arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string a,b;cin>>a>>b;
        arr[a] = b;
    }
    vector<string>v;
    for(int i=1;i<=m;i++){
        string a;cin>>a;
        v.push_back(arr[a]);
    }
    for(auto i:v){
        cout<<i<<'\n';
    }

    return 0;
}