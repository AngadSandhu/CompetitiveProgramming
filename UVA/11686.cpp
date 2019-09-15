#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define N 1000005
using namespace std;
typedef long long ll;
vector<int> adj[N];
vector<int> times;
int color[N];
int t;
bool cycle;
void dfs(int s){
	color[s] = 1;
	for(auto v : adj[s]){
		if(color[v]==0){
			dfs(v);
		}else{
			if(color[v]==1) cycle = 1;
		}
	}
	color[s] = 2;
	times.push_back(s);
}
int main(){
	int n,m;
	while(cin >> n >> m,n > 0){
		t = 0; cycle = 0;
		for(int i = 0 ; i < n ; i++) color[i] = 0,adj[i].clear();
		times.clear();
		for(int i = 0 ; i < m ; i++){
			int a,b;cin >> a >>b;
			a--;b--;
			adj[a].push_back(b);
		}
		for(int i = 0 ; i < n;i++){
			if(color[i]==0) dfs(i);
		}
		reverse(times.begin(),times.end());
		if(!cycle){
			for(auto v : times){
				cout << v+1<< endl;
			}
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
