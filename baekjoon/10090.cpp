/*#include<bits/stdc++.h>
using namespace std;

int n;
int tree[4000010];

void update(int n,int s,int e,int idx,int val){
    if(s==e){
        tree[n] = val;
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
    if(e<l||r<s||r<l)return 0;
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

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;

    }


    return 0;
}*///세그먼트 트리 풀이

/*#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<ll>tree;
void update(int idx){
    while(idx<=n){
        tree[idx]++;
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
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    tree.resize(n+1);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        ans+=query(n) - query(a);
        update(a);
    }
    cout<<ans;
    return 0;    
}*/// 펜윅 트리 풀이


/*
#include<bits/stdc++.h>
using namespace std;

long long ans;
void mergesort(vector<int>&arr,int s,int e){
    if(s==e)return;
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    queue<int>mg;
    int i = s,j = mid+1;
    while(i<=mid&&j<=e){
        if(arr[i]<=arr[j]){
            mg.push(arr[i]),i++;
        }else{
            mg.push(arr[j]),j++,ans+=(mid-i+1);
        }
    }
    while(i<=mid)mg.push(arr[i]),i++;
    while(j<=e)mg.push(arr[j]),j++;
    for(int i=s;i<=e;i++){
        arr[i] = mg.front();
        mg.pop();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;
    vector<int>arr;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }
    mergesort(arr,0,n-1);
    cout<<ans;
    return 0;
}*///머지 소트 풀이