#include<bits/stdc++.h>
using namespace std;

map<string,string>Map;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;cin>>str;
        string str_i = to_string(i);
        Map.insert({str,str_i});
        Map.insert({str_i,str});
    }
    for(int i=1;i<=m;i++){
        string str;
        cin>>str;
        cout<<Map[str]<<'\n';
        
    }

    return 0;
}