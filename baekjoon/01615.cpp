/*#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll tree[2020];
int n,m;
vector<pair<int,int>>v;
void update(int idx,int val){
    while(idx<=n){
        tree[idx] +=val;
        idx+=(idx&-idx);
    }
}
ll query(int idx){
    ll ret = 0;
    while(idx){
        ret+=tree[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
ll ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        v.emplace_back(a,b);
    }
    sort(v.begin(),v.end());

    for(auto[a,b]:v){
        ans+=query(n) - query(b);
        update(b,1);
    }
    cout<<ans;
    return 0;
}*///펜윅 트리 풀이

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>>v;
int tree[8020];
void update(int n,int s,int e,int idx,int val){
    if(s==e){
        tree[n] +=val;
        return;
    }
    int mid = (s+e)/2;
    int lch = n*2;
    int rch = n*2+1;
    if(idx<=mid){
        update(lch,s,mid,idx,val);
    }else{
        update(rch,mid+1,e,idx,val);
    }
    tree[n] = tree[lch] + tree[rch];
}
int query(int n,int s,int e,int l,int r){
    if(r<s||e<l||r<l)return 0;
    if(l<=s&&e<=r)return tree[n];
    int mid = (s+e)/2;
    int lch = n*2;
    int rch = n*2+1;
    return query(lch,s,mid,l,r) + query(rch,mid+1,e,l,r);
}
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        v.emplace_back(a,b);
    }
    sort(v.begin(),v.end());
    for(auto[a,b]:v){
        ans+=query(1,1,n,b+1,n);
        update(1,1,n,b,1);
    }
    cout<<ans;
    return 0;//세그먼트 트리 풀이
}