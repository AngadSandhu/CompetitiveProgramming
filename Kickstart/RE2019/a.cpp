#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n, m;
vector<int> adj[100005];
bool visit[100005];
int bfs(int s){
	queue<int> q;
	q.push(s);
	visit[s] = 1;
	int c = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		c++;
		for(auto v : adj[u]){
			if(visit[v]) continue;
			visit[v] = 1;
			q.push(v);
		}
	}
	return c;
}
int main(){
	int t;cin >> t;
	int p = 0;
	while(t--){
		p++;
		cin >> n >> m;
		for(int i = 0; i < n ; i++){
			adj[i].clear();
			visit[i] = 0;
		}
		for(int i = 0 ; i < m ; i++){
			int x,y;
			cin >> x >>y;
			x--;y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int res = 0 , c = 0;
		for(int i =0 ; i < n ; i++){
			if(visit[i]==0){
				res += bfs(i) -1;
				c++;
			}
		}
		res += 2*(c-1);
		printf("Case #%d: %d\n",p,res);
	}
	return 0;
}
