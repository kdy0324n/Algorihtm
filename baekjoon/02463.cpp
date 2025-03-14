#include<bits/stdc++.h>
using namespace std; 

const int MOD = 1e9;
const int MAX = 100010; 

int N, M;

int par[MAX];
using ll = long long;
using piii = pair<pair<int,int>,int>;
vector <piii> adj; 
ll val[MAX], Sum; 

int Find(int u) {
        if (par[u]==0)return u;
        int ret = Find(par[u]);
        par[u] = ret;
        return ret;
}
 

//num1의 집합에 num2 집합을 합친다

void Union(int u,int v) {
    par[u] = v;
    val[v]+=val[u];
    val[u]=1;
}

 

bool cmp(piii l, piii r){return l.second>r.second;} 

int main(void) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> M; 

        for (int i = 1; i <= N; i++) {
            val[i]=1;
        }

        for(int i=1;i<=M;i++){
            int a,b,c;cin>>a>>b>>c;
            Sum+=c;
            adj.push_back({{a,b},c});
        }

        sort(adj.begin(), adj.end(), cmp); //가중치 내림차순 정렬

       

        long long result = 0;

        for (int i = 0; i < adj.size(); i++)

        {
                 int u = Find(adj[i].first.first);
                 int v = Find(adj[i].first.second);
                 int cost = adj[i].second;  

                 if (u!=v) {
                         result += (((val[u] * val[v]) % MOD) * Sum) % MOD;
                         result %= MOD;
                         Union(u,v);
                 }

                 Sum -= cost;

        }

        cout << result << "\n";

        return 0;

}
