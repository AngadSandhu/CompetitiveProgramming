#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int n,m;
vector<int> adj[N];
vector<int> top;
bool vis[N];
void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  for(auto v : adj[u]){
    dfs(v);
  }
  top.pb(u);
}
int main(){
	FIO;
	while(cin >> n >> m){
    if(n == 0 && m==0) break;
    int x,y;
    for(int i = 0 ; i < m ; i++){
      cin >> x >> y;
      x--,y--;
      adj[x].pb(y);
    }
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
      dfs(i);
      for(int j = 0 ; j < top.size() ; j++) ans.pb(top[j]);
      top.clear();
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0 ; i < ans.size() ; i++){
      if(i) cout << " ";
      cout << ans[i]+1;
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++) adj[i].clear();
    memset(vis,0,sizeof vis);
  }
	return 0;
}