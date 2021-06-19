#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 3005
int n,m,k;
char a[N][N];
int d[N][N];
pair<int,int> par[N][N];
set<pair<int,pair<int,int>>> st;
vector<int> adj[N];
void bfs(pair<int,int> s){
	queue<pair<int,int>>q;
	d[s.first][s.second] = 0;
	q.push(s);
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(auto v : adj[u.second]){
      pair<int,int> nv = {u.second,v};
      if(st.find({u.first,nv}) != st.end()) continue;
      if(d[nv.first][nv.second] == -1){
        q.push(nv);
        d[nv.first][nv.second] = d[u.first][u.second] + 1;
        par[nv.first][nv.second] = u;
      }
		}
	}
}
int main(){
	FIO;
  memset(d,-1,sizeof d);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      par[i][j] = {-1,-1};
    }
  }
	cin >> n >> m >> k;
  int x,y;
  for(int i = 0 ; i < m ; i++){
    cin >> x >> y; x--,y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  for(int i = 0 ; i < k ; i++){
    int a,b,c; cin >> a >> b >> c; a--,b--,c--;
    st.insert({a,{b,c}});
  }
  bfs({0,0});
  int ans = INT_MAX;
  pair<int,int> currNode = {-1,-1};
  for(int i = 0 ; i < n ; i++){
    if(d[i][n-1] != -1 && ans > d[i][n-1]){
      ans = d[i][n-1];
      currNode = {i,n-1};
    }
  }
  
  //cout << par[0][2].first+1 << " " << par[0][2].second+1 << endl;
  par[0][0] = {-1,-1};
  vector<int> path;
  while(currNode != make_pair(-1,-1)){
    //cout << par[currNode.first][currNode.second].first+1 << " " << par[currNode.first][currNode.second].second+1 << endl;
    path.pb(currNode.second);
    currNode = par[currNode.first][currNode.second];
  }
  ans = (ans==INT_MAX ? -1:ans);
  cout << ans << endl;
  reverse(path.begin(),path.end());
  for(auto v: path) cout << v+1 << " "; cout << endl;
	return 0;
}