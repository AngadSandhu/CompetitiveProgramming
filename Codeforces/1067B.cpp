#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll deg[1000005];
vector<int>adj[100005];
int d[1000005];
bool b = 1;
int n,k;
int mx = -1;
void clearq(queue<int> &q){
   queue<int> empty;
   swap( q, empty );
}
void bfs(int s){
	queue<int> q;
	d[s] = 0;
	q.push(s);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(d[v]==-1) d[v] = d[u] + 1, q.push(v),mx = max(mx,d[v]);
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(adj[i].size()==1 && d[i]!=mx) b = 0;//cout << d[i] << endl;
	}
}
int main(){
	cin >> n >> k;
	memset(d,-1,sizeof d);
	for(int i = 0 ; i < n-1; i++){
		int u,v; cin >> u >> v; u--; v --;
		deg[u] ++ ; deg[v]++;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	int cnt = 0,c = 0,center;
	queue<int> q1,q2;
	for(int i = 0 ; i < n ; i++){
		if(deg[i]==1) q1.push(i);
	}
	while(!q1.empty()){
		int u = q1.front();
		q1.pop();
		c++;
		for(auto v : adj[u]){
			deg[v]--;
			if(deg[v]==1) q2.push(v);
		}
		if(q1.empty()&&!q2.empty()) q1 = q2, clearq(q2),cnt++;
		if(c==n){
			center= u;
		}
	}
	for(int i = 0 ;  i < n  && b; i++){
		if(i!=center) if(adj[i].size()<=3&&adj[i].size()>1) b = 0;
	}
	if(adj[center].size()<3) b = 0;
	bfs(center);
	cout << (b&&c==n&&mx==k? "Yes":"No") << endl;
	return 0;
}
