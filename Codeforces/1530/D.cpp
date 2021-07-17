#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int inDeg[N], a[N], comp[N], ans[N];
bool vis[N];
vector<int> lazo[N];
void dfs(int u,int c){
  vis[u] = 1;
  comp[u] = c;
  lazo[comp[u]].pb(u);
  if(vis[a[u]] == 0){
    dfs(a[u],c);
  }
  vis[u] = 2;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i], inDeg[a[i]]++;
    int ncomp = 0;
    for(int i = 1 ; i <= n ; i++){
      if(inDeg[i] == 0){
        dfs(i,ncomp++);
      }
    }
    for(int i = 1 ; i < ncomp ; i++){
      for(int j = 0 ; j < lazo[i].size() ; j++){
        lazo[0].pb(lazo[i][j]);
      }
      lazo[i].clear();
    }
    ncomp = 1;
    for(int i = 1 ; i <= n ; i++){
      if(vis[i] == 0){
        dfs(i,ncomp++);
      }
    }
    for(int i = 0 ; i < ncomp ; i++){
      for(int j = 0 ; j < lazo[i].size() ; j++){
        ans[lazo[i][j]] = lazo[i][(j+1)%lazo[i].size()];
      }
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++) cnt += ans[i] == a[i];
    cout << cnt << endl;
    for(int i = 1 ; i <= n ; i++) 
      cout << ans[i] << " "; 
    cout << endl;
    for(int i = 0 ; i <= n ; i++) 
      inDeg[i] = 0, vis[i] = 0, comp[i] = 0, lazo[i].clear(); 
  }
	return 0;
}