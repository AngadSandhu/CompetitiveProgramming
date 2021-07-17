#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int dmax = 0, st[N][20], dep[N];
int n,q;
vector<int> adj[N];
void dfs(int u,int p,int h){
	st[u][0] = p;
	dep[u] = h;
	dmax = max(dmax,h);
	for(auto v : adj[u]){
		if(v == p) continue;
		dfs(v,u,h+1);
	}
}
void buildlca(){
	for(int j = 1 ; (1<<j) <= dmax ; j++){
		for(int i = 0 ; i < n  ; i++){
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}
}
int getlca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	int bit = 31 - __builtin_clz(dep[u]);
	for(int i = bit ; i >= 0 ; i--){
		if(dep[st[u][i]] >= dep[v]) u = st[u][i];
	}
	bit = 31 - __builtin_clz(dep[u]);
	for(int i = bit ; i >= 0 ; i--){
		if(st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
	}
	if(u==v) return u;
	return st[u][0];
}
map<string,int> id;
int inDeg[N];
int main(){
	FIO;
	cin >> n >> q;
  for(int i = 0 ; i < n ; i++){
    string s,t; cin >> s;
    if(id.count(s) == 0) id[s] = id.size();
    int cnt; cin >> cnt;
    while(cnt--){
      cin >> t;
      if(id.count(t) == 0) id[t] = id.size();
      adj[id[s]].pb(id[t]);
      adj[id[t]].pb(id[s]);
      inDeg[id[t]]++;
    }
  }
  n = id.size();
  for(int i = 0 ; i < n ; i++){
    if(inDeg[i] == 0){
      dfs(i,i,0);
      break;
    }
  }
  //for(int i = 0 ; i < n ; i++) cout << dep[i] << endl;
  buildlca();
  while(q--){
    string u,v,nu,nv; cin >> u >> v; nu =u, nv = v;//cout << id[u] << " " << id[v] << endl;
    int lca = getlca(id[u],id[v]);
    int x = dep[id[u]] - dep[lca], y = dep[id[v]] - dep[lca];
    if(x > y) swap(u,v), swap(x,y);
    //cout << x << " " << y << " " << u << " " << v << " " << lca << endl;
    if(x == 0){
      if(y==1) cout << v << " is the child of " << u << endl;
      else{
        cout << v << " is the ";
        for(int i = 0 ; i < y-2 ; i++) cout << "great ";
        cout << "grandchild of " << u << endl;
      }
    }else if(x > 0 && x == y){
      if(y==1) cout << nu << " and " << nv << " are siblings" << endl;
      else{
        int cousin = y-1;
        string Scousin;
        if(cousin%10 == 1 && cousin != 11) Scousin = "st";
        else if(cousin%10 == 2 && cousin != 12) Scousin = "nd";
        else if(cousin%10 == 3 && cousin != 13) Scousin = "rd";
        else  Scousin = "th";
        cout << nu << " and " << nv << " are " << cousin << Scousin << " cousins" << endl;
      }
    }else if(x > 0 && x < y){
      int cousin = x-1;
      string Scousin;
      if(cousin%10 == 1 && cousin != 11) Scousin = "st";
      else if(cousin%10 == 2 && cousin != 12) Scousin = "nd";
      else if(cousin%10 == 3 && cousin != 13) Scousin = "rd";
      else  Scousin = "th";
      cout << nu << " and " << nv << " are " << cousin << Scousin << " cousins, " << y-x << (y-x==1 ? " time" : " times" ) << " removed" << endl;
    }
  }
	return 0;
}