#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        int k = 1;map<string,int>m;
        cin>>n;
        if(n==0){
            v.push_back(0);
            continue;
        }
        for(int i=1;i<=n;i++){
            string name,str;
            cin>>name>>str;
            if(m.find(str)!=m.end()){
                m[str]++;
            }
            else{
                m.insert({str,1});
            }
        }
        if(m.size()==1){
            v.push_back(n);
            continue;
        }
        for(auto i=m.begin();i!=m.end();i++){
            k*= i->second + 1;
        }
        v.push_back(k-1);
    }
    for(auto i:v){
        cout<<i<<'\n';
    }

    return 0;
}