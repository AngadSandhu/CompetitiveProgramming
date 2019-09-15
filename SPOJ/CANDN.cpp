#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n,m,S,A,B;
vector<ii> adj[5005];
ll d[3][5005];

void dij(int id, int s){
	priority_queue<pair<ll,int>> q;
	d[id][s] = 0;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		for(auto v : adj[u]){
			int vv = v.second, w = v.first;
			if(d[id][vv] > d[id][u]+w){
				d[id][vv] = d[id][u]+w;
				q.push({-d[id][vv],vv});
			}
		}
	}
}
int main() {
	while(cin >> n >> S >> A >> B >> m && n>0){
		S--; A--; B--;
		for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < 3 ; j++) d[j][i] = ll(1e10), adj[i].clear();
		for(int i = 0; i < m ; i++){
			int x,y,w;
			cin >> x >> y >> w;
			adj[--x].push_back({w,--y});
			adj[y].push_back({w,x});
		}
		dij(0,S);
		dij(1,A);
		dij(2,B);
		ll mx = 0;
		ll da = d[0][A], db = d[0][B];
		for(int i = 0 ; i < n ; i++){
			if((da==d[0][i]+d[1][i]) && (db==d[0][i]+d[2][i])) mx = max(mx,d[0][i]);
		}
	cout << mx << " " << da-mx << " " << db-mx <<  endl;
	}
	return 0;
}
