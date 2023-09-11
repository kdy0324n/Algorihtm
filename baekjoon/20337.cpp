#include<bits/stdc++.h>//
using namespace std;

int n;
int arr[100010];
int chk[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];     
    
    int k = n/4;
    int Start = 1;
    int End = k;
    cout<<3<<'\n';
    for(int i=1;i<=3;i++){
        priority_queue<int,vector<int>,greater<int>>pq,idx;//값
        memset(chk,0,sizeof(chk));
        for(int j=Start;j<=n;j++){
            if(Start<=arr[j]&&arr[j]<=End){
                pq.push(arr[j]);
                idx.push(j);
                chk[j]=1;
                if(pq.size()>=k)break;                
            }
        }
        for(int j=Start;j<=n;j++){
            if(chk[j])continue;
            pq.push(arr[j]);
            idx.push(j);
            chk[j]=1;
            if(pq.size()>=n/2)break;
        }
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            int tidx = idx.top();idx.pop();
            arr[tidx] = t;
            cout<<tidx<<' ';
        }
        cout<<'\n';
        Start+=k;
        End+=k;
    }
    
    return 0;
}