#include<bits/stdc++.h>
using namespace std;
#define N 205
int n,m;
vector<int>adj[N];
int id[N];
bool b = 1;
void dfs(int s){
	for(auto v : adj[s]){
		if(id[v]==-1){
			id[v] = !id[s];
			dfs(v);
		}else if(id[s]==id[v]) b = 0;
	}
}
int main(){
	while(cin >> n, n > 0){
		b = 1;
		for(int i = 0 ; i < n ; i++) adj[i].clear(), id[i] = -1;
		cin >> m;
		for(int i = 0 ; i < m ; i++){
			int x,y;
			cin >> x>> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		id[0] = 0;
		dfs(0);
		cout << (b?"BICOLORABLE.":"NOT BICOLORABLE.") << endl;
	}
		return 0;
}
