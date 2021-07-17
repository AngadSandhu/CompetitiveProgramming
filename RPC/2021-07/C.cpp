#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int n; 
map<string,string> edge;
ll d[N][N];
map<string,bool> vis;
int ans = -1;
void dfs(string u,int d){
  if(vis[u]){
    ans = max(ans,d);
    return;
  }
  vis[u] = 1;
  if(edge.count(u)) dfs(edge[u],d+1);
}
int main(){
	FIO;
	cin >> n;
  string s,x,y;
  vector<string> nodes;
  for(int i = 0 ; i < n ; i++){
    cin >> s >> x >> y;
    nodes.pb(x);
    nodes.pb(y);
    edge[x] = y;
  }
  for(int i = 0 ; i < nodes.size() ; i++){
    if(vis[nodes[i]]) continue;
    dfs(nodes[i],0);
  }
  if(ans == -1) cout << "No trades possible" <<endl;
  else cout << ans << endl;
	return 0;
}