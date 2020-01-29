#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,k;
vector<int> adj[N];
bool visit[N];
int comp = 0;
void bfs(int s){
	visit[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(visit[v]==0){
				visit[v] = 1;
				q.push(v);
			}
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i = 0 ; i < k ; i++){
		int x,y; cin >> x >> y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	for(int i = 0 ; i < n ;i++){
		if(visit[i]==0){
			comp++;
			bfs(i);
		}
	}
	cout << k-(n-comp) << endl;
	return 0;
}
