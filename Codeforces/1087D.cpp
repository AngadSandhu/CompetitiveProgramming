#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int main(){
	int n,s;
	cin >> n >> s;
	for(int i = 0 ; i < n-1 ; i++){
		int u,v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int c = 0;
	for(int i = 0 ; i < n ; i++){
		if(adj[i].size()==1) c++; 
	}
	printf("%.6lf\n",2.0*s/c);
	return 0;
}
