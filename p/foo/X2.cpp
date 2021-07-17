#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int n;
vector<pair<int,int>> adj[N];
int pref[N][2], dp[N][2];
int dfs(int u, int p){
  int ans = 0;
  // frontera decreciente
  int befWeight = -1, carryDp = 0;
  for(int i = 0 ; i < adj[u].size() ; i++){
    int v = adj[u][i].first, w = adj[u][i].second;
    if(v == p) continue;
    ans = max(ans,dfs(v,u));
    pref[u][0] = pref[u][1] = 1;
    for(auto edge2 : adj[v]){
      int v2 = edge2.first, w2 = edge2.second;
      if(w2 == w) continue;
      if(w2 < w) pref[u][0] = max(pref[u][0], 2 + pref[v2][0]); //decre
      else pref[u][1] = max(pref[u][1], 2 + pref[v2][1]); //cre
    }
    if(befWeight != w) dp[u][0] += carryDp, carryDp = pref[u][0];
    else carryDp += pref[u][0];
    befWeight = w;
    ans = max(ans,dp[u][0] + pref[u][1]);
  }
  return ans;
}
bool comp(pair<int,int> p1, pair<int,int> p2){
  return p1.second < p2.second;
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
  for(int i = 0 ; i < n ; i++) sort(adj[i].begin(),adj[i].end(),comp);
  cout << dfs(0,-1) << endl;
	return 0;
}