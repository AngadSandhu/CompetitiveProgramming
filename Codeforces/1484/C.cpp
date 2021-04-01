#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
vector<int> adj[N];
bool vis[N];
int degree[N];
bool comp(int a, int b){return degree[a] < degree[b];}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n,m; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
      int k ; cin >> k;
      degree[i] = k;
      for(int j = 0 ; j < k ; j++){
        int x; cin >> x;
        adj[x].pb(i);        
      }
    }
    vector<int> ans(m);
    int limit = (m+1)/2;
    for(int i = 1 ; i <= n ; i++){
      sort(adj[i].begin(),adj[i].end(),comp);
      int used = 0;
      for(auto v : adj[i]){
        if(vis[v]) continue;
        if(used == limit) break;
        vis[v] = 1;
        used++;
        ans[v-1] = i;
      }
    }
    bool yes = 1;
    for(int i = 1 ; i <= m ; i++) if(vis[i]==0) yes = 0;
    if(yes){
      cout << "YES" << endl;
      for(auto x : ans) cout << x << " "; cout << endl;
    }else{
      cout << "NO" << endl;
    }
    for(int i = 1 ; i <= m ; i++) vis[i] = 0;
    for(int i = 1 ; i <= n ; i++) adj[i].clear();
  }
	return 0;
}