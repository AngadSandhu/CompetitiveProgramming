#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int n,m;
vector<int> adj[N];
int d[N];
bool side[N];
void bfs(int s){
  for(int i = 0 ; i < n ; i++) d[i] = -1;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while(!q.empty()){
    auto u = q.front();
    q.pop();
    for(auto v : adj[u]){
      if(d[v] != -1) continue;
      d[v] = !d[u];
      q.push(v);
    }
  }
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n >> m;
    int x,y;
    for(int i = 0 ; i < m ; i++){
      cin >> x >> y;
      x--,y--;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    bfs(0);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
      cnt1 += d[i];
    }
    cnt2 = n-cnt1;
    if(cnt1 < cnt2){
      cout << cnt1 << endl;
      for(int i = 0 ; i < n ; i++){
        if(d[i]) cout << i+1 << " ";
      }
      cout << endl;
    }else{
      cout << cnt2 << endl;
      for(int i = 0 ; i < n ; i++){
        if(!d[i]) cout << i+1 << " ";
      }
      cout << endl;
    }
    for(int i = 0 ; i < n ; i++) adj[i].clear();
  }
	return 0;
}