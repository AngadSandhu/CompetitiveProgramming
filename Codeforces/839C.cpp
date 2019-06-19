#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
double res = 0;
void dfs(int s,int p,int d,double prob){
	if(adj[s].size()==1){
		res += prob*d;
	}else if(s==0){
		prob *= 1.0/(adj[s].size());
	}else{
		prob = prob/(adj[s].size()-1);
	}
	for(auto v : adj[s]){
		if(v==p) continue;
		dfs(v,s,d+1,prob);
	}
}
int main(){
	int n; cin >> n;
	for(int i = 0 ; i < n-1 ; i ++){
		int u,v; cin >> u >> v; v--; u--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,-1,0,1.0);
	printf("%.6f\n",res);
	return 0;
}
