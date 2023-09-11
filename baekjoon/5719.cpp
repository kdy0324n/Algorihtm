#include<bits/stdc++.h>
using namespace std;

int n, m;
int s, e;
int chk[510][510];
using pii = pair<int, int>;
using piii = pair<int, pii>;
int dist[510];
int inf = 1e9;
int arr[510][510];

vector<vector<int>>dijkstra(vector<pii>adj[510],int u) {
	vector<vector<int>>back_adj;
	back_adj.resize(510);
	for (int i = 0; i <= n; i++)dist[i] = inf;
	priority_queue<piii, vector<piii>, greater<piii>>pq;//값, 인덱스, 부모인덱스
	pq.push({ 0,{u,-1} });
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		if (dist[t.second.first] < t.first)continue;
		dist[t.second.first] = t.first;
		back_adj[t.second.first].push_back(t.second.second);

		for (auto i : adj[t.second.first]) {
			int nidx = i.first;
			int ncost = i.second + t.first;
			if (chk[t.second.first][nidx])continue;
			if (dist[nidx] >= ncost) {
				pq.push({ ncost,{nidx,t.second.first} });
			}
		}
	}
	return back_adj;
}
int chk1[510];
void bfs(vector<vector<int>>back_adj) {
	queue<int>q;
	q.push(e);
	while (!q.empty()) {
		int cur = q.front();        
		q.pop();
        if(cur==s)continue;
        for(auto i:back_adj[cur]){ 
            if(chk[i][cur])continue;
            if(dist[cur]==dist[i] + arr[i][cur]){
                q.push(i);
                chk[i][cur]=1;
            }
        }
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cin >> s >> e;
		vector<pii>adj[510];
		memset(chk, 0, sizeof(chk));
		memset(chk1, 0, sizeof(chk1));
        memset(arr,0,sizeof(arr));
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].emplace_back(b, c);
            arr[a][b] = c;
		}
		vector<vector<int>>back_adj = dijkstra(adj, s);
		bfs(back_adj);
		dijkstra(adj, s);
		if (dist[e] == inf)cout << -1;
		else cout << dist[e];
		cout << '\n';

	}


	return 0;
}