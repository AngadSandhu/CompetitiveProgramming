#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10005];
int maxi = -1;
int farest = -1;
void dfs(int s, int d,int p){
	if(d>maxi){
		farest = s;
		maxi = d;
	}
	for(auto v : adj[s]){
		if(v==p) continue;
		dfs(v,d+1,s);
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n-1 ; i++){
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,0,-1);
	dfs(farest,0,-1);
	cout << maxi << endl;
	return 0;
}
