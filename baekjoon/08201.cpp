#include<bits/stdc++.h>
using namespace std;
//투 포인터 방식
int arr[3000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    cin>>t>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    deque<pair<int,int>>max_dq,min_dq;
    int ans=0;
    for(int i=1,j=1;i<=n;i++){
        
        while(max_dq.size()&&max_dq.back().first<=arr[i])max_dq.pop_back();
        while(min_dq.size()&&min_dq.back().first>=arr[i])min_dq.pop_back();
        max_dq.push_back({arr[i],i});
        min_dq.push_back({arr[i],i});
        while(max_dq.front().first-min_dq.front().first>t){
            if(max_dq.front().second<min_dq.front().second)j=max_dq.front().second+1,max_dq.pop_front();
            else j=min_dq.front().second+1,min_dq.pop_front();
        }
        ans = max(ans,i-j+1);
    }
    cout<<ans;


    return 0;
}