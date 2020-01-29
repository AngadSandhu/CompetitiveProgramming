#include<bits/stdc++.h>
using namespace std;
#define N 505
bool st[N];
int f,n;
vector<pair<int,int>> adj[N];
int dm[N],d[N][N];
void dij(int s){
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	d[s][s] = 0;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(st[u]) dm[s] = min(d[s][u],dm[s]);
		for(auto h : adj[u]){
			int v = h.second, w = h.first;
			if(d[s][v] > d[s][u] + w){
				d[s][v] = d[s][u] + w;
				q.push({-d[s][v],v});
			}
		}
	}
}
int main(){
	int t;cin >> t;
	int p = 0;
	while(t--){
		if(p++!=0) cout << endl;
		cin >> f >> n;
		for(int i = 0 ; i < n ; i++){
			dm[i] = INT_MAX;
			st[i] = 0;
			adj[i].clear();
			for(int  j = 0 ; j < n ; j ++) d[i][j] = INT_MAX;
		}
		for(int i = 0 ; i < f ; i++){ int x; cin >> x; st[--x] = 1; }
		string s;
		cin.ignore();
		while(getline(cin,s)){
			if(s=="") break;
			stringstream in(s);
			int x,y,w; in >> x >> y >> w;
			adj[--x].push_back({w,--y});
			adj[y].push_back({w,x});
		}
		for(int i = 0 ;i < n ; i++){
			dij(i);
		}
		int id, mn = INT_MAX,mx;
		for(int i = 0 ;i < n ; i++){
			mx = INT_MIN;
			for(int j = 0 ;  j< n ; j++){
				mx = max(min(dm[j],d[j][i]),mx); 
			}
			if(mn > mx){
				mn = mx;
				id = i+1;
			}
		}
		cout << id << endl;
	}
	return 0;
}
