#include<bits/stdc++.h>
using namespace std;

int n,m;
set<string>s;
vector<string>ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        string str;cin>>str;
        s.insert(str);
    }
    for(int i=1;i<=m;i++){
        string str;cin>>str;
        if(!s.insert(str).second){
            ans.push_back(str);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i:ans){
        cout<<i<<'\n';
    }
    return 0;
}