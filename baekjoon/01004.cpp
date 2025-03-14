#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int n;
        cin>>n;
        int ans = 0;
        for(int i=1;i<=n;i++){
            int x,y,r;
            cin>>x>>y>>r;
            int a=x-r;
            int b = x+r;
            int c = y-r;
            int d = y+r;
            if(a<x1&&x1<b&&c<y1&&y1<d&&a<x2&&x2<b&&c<y2&&y2<d)continue;
            if(a<x1&&x1<b&&c<y1&&y1<d)ans++;
            else if(a<x2&&x2<b&&c<y2&&y2<d)ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}