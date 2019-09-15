#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define N 1000005
using namespace std;
typedef long long ll;
vector<int> adj[305];
int d[305];
bool bip;
void bfs(int s){
	queue<int> q;
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(d[v]==-1){
				d[v] = !d[u];
				q.push(v);
			}else{
				if(d[v]==d[u]) bip = 0;
			}
		}
	}
}
int main(){
	int n;
	while(cin >> n,n>0){
		bip = 1;
		memset(d,-1,sizeof(d));
		for(int i = 0 ; i< n ; i++) adj[i].clear();
		int a,b;
		while(cin >> a >>b){
			if(a==0&&b==0) break;
			a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bfs(0);
		cout << (bip?"YES":"NO") << endl;
	}
	return 0;
}
