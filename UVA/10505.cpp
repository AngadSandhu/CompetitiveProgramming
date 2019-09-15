#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define N 1000005
using namespace std;
typedef long long ll;
vector<int> adj[305];
int d[305];
int res[2];
bool bip;
int bfs(int s){
	queue<int> q;
	d[s] = 0;
	q.push(s);
	res[0]=res[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		res[d[u]]++;
		for(auto v : adj[u]){
			if(d[v]==-1){
				d[v] = !d[u];
				q.push(v);
			}else if(d[v]==d[u]) bip = 0;
		}
	}
	return max(res[0],res[1]);
}
int main(){
	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		bip = 1;
		res[0] = res[1] = 0;
		for(int i = 0 ; i< n ; i++) adj[i].clear(),d[i] = -1;
		for(int i = 0 ; i <n ; i++){
			int cnt; cin >> cnt;
			while(cnt--){
				int b; cin >> b; b--;
				adj[i].push_back(b);
				if(find(adj[b].begin(),adj[b].end(),i)==adj[b].end())
				adj[b].push_back(i);
			}
		}
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			bip = 1;
			if(d[i]==-1) ans += bfs(i)*bip;
		}
		cout << ans << endl;
	}
	return 0;
}
