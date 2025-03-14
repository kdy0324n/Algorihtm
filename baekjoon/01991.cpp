#include<bits/stdc++.h>
using namespace std;

pair<int,int>node[27];

void preorder(int cur){
    if(cur<0)return;
    printf("%c",cur+64);
    preorder(node[cur].first);
    preorder(node[cur].second);
}

void inorder(int cur){
    if(cur<0)return;
    inorder(node[cur].first);
    printf("%c",cur+64);
    inorder(node[cur].second);
}

void postorder(int cur){
    if(cur<0)return;
    postorder(node[cur].first);
    postorder(node[cur].second);
    printf("%c",cur+64);
}

int main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        a-=64,b-=64,c-=64;
        node[a].first=b;
        node[a].second=c;
    }
    preorder(1);
    cout<<'\n';
    inorder(1);
    cout<<'\n';
    postorder(1);
}