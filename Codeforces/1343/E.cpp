#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int n,m,a,b,c;
vector<int> adj[N];
ll p[N];
int parent[N];
int d[5][N];
void bfs(int s,int id){
	for(int i = 0 ; i < n ; i++) d[id][i] = -1;
	d[id][s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(d[id][v] == -1){
				d[id][v] = d[id][u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> a >> b >> c;
		a--,b--,c--;
		for(int i = 0 ; i < m ; i++) cin >> p[i];
		sort(p,p+m);
		for(int i = m ; i >= 1 ; i--) p[i] = p[i-1];
		p[0] = 0;
		for(int i = 0 ; i < m ; i++) p[i+1] += p[i];
		int u,v;
		for(int i = 0 ; i < m ; i++){
			cin >> u >> v;
			u--,v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);
		ll res = 1e18;
		for(int x = 0 ; x < n ; x++){
			if(d[0][x] + d[1][x] + d[2][x] <= m) res = min(res,p[d[1][x]] + p[d[0][x] + d[1][x] + d[2][x]]);
		}
		cout << res << endl;
		for(int i = 0 ; i < n ; i++) adj[i].clear();
	}
	return 0;
}