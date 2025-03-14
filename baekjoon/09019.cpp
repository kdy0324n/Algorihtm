#include<bits/stdc++.h>
using namespace std;

int n,ans;
int chk[10010];
queue<pair<int,string>>q;

string bfs(){
    while(!q.empty()){
        int t = q.front().first;
        string t2 = q.front().second;
        int tmp = t;
        int a = tmp/1000;tmp%=1000;
        int b = tmp/100;tmp%=100;
        int c = tmp/10;tmp%=10;
        int d = tmp;
        q.pop();


        if(ans==t){
            return t2;
        }

        int D = t*2%10000;
        if(!chk[D]){
            chk[D]=1;
            q.push({D,t2+"D"});
        }
        int S = (t+10000-1)%10000;
        if(!chk[S]){
            chk[S]=1;
            q.push({S,t2+"S"});
        }
        int L = b*1000 + c*100 + d*10 + a;
        if(!chk[L]){
            chk[L]=1;
            q.push({L,t2+"L"});
        }
        int R = d * 1000 + a*100 + b*10+c;
        if(!chk[R]){
            chk[R]=1;
            q.push({R,t2+"R"});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;cin>>T;
    while(T--){
        cin>>n>>ans;

        while(!q.empty())q.pop();
        memset(chk,0,sizeof(chk));
        q.push({n," "});
        chk[n]=1;
         cout<<bfs()<<'\n';
    }
    


    return 0;
}