#include <bits/stdc++.h>
using namespace std;
vector<int>adj[200005];
int maxi = -1;
int farest = -1;
int d[3][200005];
void dfs(int s,int p,int id){
	for(auto v : adj[s]){
		if(v==p) continue;
		d[id][v] = d[id][s] + 1;
		if(d[id][v]>maxi){
			farest = v;
			maxi = d[id][v];
		}
		dfs(v,s,id);
	}
	return;
}
int main() {
	int t; cin>> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0 ; i < n ; i++) adj[i].clear();
		maxi = -1;
		for(int i = 0 ; i < n-1 ; i++){
			int u, v;
			scanf("%d %d",&u,&v); u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		d[0][0] = 0;
		dfs(0,-1,0);
		
		int aux = farest;
		maxi = -1;
		d[1][aux] = 0;
		dfs(aux,-1,1);

		d[2][farest] = 0;
		dfs(farest,-1,2);
		double res = 0;
		for(int i = 0 ; i < n; i++){
			res += max(d[1][i],d[2][i]);
			//cout << i+1 << " " << d[1][i] << " " <<d[2][i] << endl;
		}
		cout << res/n << endl;
	}
	return 0;
}
