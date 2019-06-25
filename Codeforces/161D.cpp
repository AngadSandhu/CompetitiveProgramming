#include <bits/stdc++.h>
using namespace std;
#define N 50005
typedef long long ll;
ll pp[N][505];
int parent[N];
vector<int> adj[N];
int n, k;
ll fpp(int s, int d){
	if(pp[s][d]!=-1) return pp[s][d];
	ll ret = 0;
	if(d==0) return pp[s][d] = 1;
	for(auto v : adj[s]){
		if(parent[v] == -1) parent[v] = s;
		if(v==parent[s]) continue;
		ret += fpp(v,d-1);
	}
	return pp[s][d] = ret;
}
ll fdp(int s, int d){
	ll ret = 0;
	ret += 2*pp[s][d];
	for(auto v : adj[s]){
		if(v==parent[s]) continue;
		for(int i = 0 ; i <= d-2 ; i++){
			ret += pp[v][i]*(pp[s][d-1-i] - pp[v][d-2-i]);
		}
		ret += 2*fdp(v,d);
	}
	ret /= 2;
	return ret;
}
int main() {
	cin >> n >> k;
	for(int i = 0 ; i < n-1 ; i++){
		int u,v; cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	for(int i = 0 ; i < n ; i++){
		parent[i] = -1;
		for(int j = 0 ; j <= k ; j++){ 
			pp[i][j]=-1; 
		}
	}
	parent[0] = -2;
	int aux;
	for(int i = 0 ; i < n ; i++){
		pp[i][0] = 1;
		for(int j = 1 ; j <= k ; j++)
			aux = fpp(i,j);
	}
	cout << fdp(0,k) << endl;
	return 0;
}

