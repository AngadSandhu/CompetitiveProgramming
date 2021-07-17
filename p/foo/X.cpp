#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
#define W 105
int n;
vector<pair<int,int>> adj[N];
int pref[N][W][2], dp[N][W][2];
int dfs(int u, int p){
  int ans = 0;
  for(auto edge : adj[u]){
    int v = edge.first, w = edge.second;
    if(v == p) continue;
    ans = max(ans,dfs(v,u));
    for(int i = 0 ; i < W ; i++){
      if(i==w) continue;
      if(i < w) pref[u][w][0] = max(pref[u][w][0], 1 + pref[v][i][0]); //decre
      else pref[u][w][1] = max(pref[u][w][1], 1 + pref[v][i][1]); //cre
     
    }
    for(int i = 0 ; i < W ; i++){
      if(i==w) continue;
      if(i < w) ans = max(ans,dp[u][i][0] + pref[u][w][1]);
      else ans = max(ans,dp[u][i][1] + pref[u][w][0]);
    }
    dp[u][w][0] += pref[u][w][0];
    dp[u][w][1] += pref[u][w][1];
  }
  return ans;
}
int main(){
	FIO;
	cin >> n;
  int u,v,w;
  for(int i = 0 ; i < n-1 ; i++){
    cin >> u >> v >> w; u--,v--;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }
  cout << dfs(0,-1) << endl;
	return 0;
}