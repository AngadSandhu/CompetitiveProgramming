#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
vector<int>adj[100005];
int n;
int v[100005];
int main(){
	cin>>n;
	for(int i =0; i< n-1 ; i++){
		int u,v;
		cin >>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	queue<int> q,q2;
	for(int i = 0 ; i < n ; i++){
		if(adj[i].size()==1){ q.push(i); v[i] = 1; } 
	}
	for(int i =  0 ; i < n ; i++){
		
	}
	return 0;
}
