#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int n,m,inDeg[N];
vector<int> adj[N];
map<string,int> id;
string ar[N];
vector<int> ans;
void topological(){
  priority_queue<int> pq;
  for(int i = 0 ; i < n ; i++){
    if(inDeg[i] == 0) pq.push(-i);
  }
  while(!pq.empty()){
    int u = -pq.top();
    pq.pop();
    ans.pb(u);
    for(auto v : adj[u]){
      inDeg[v]--;
      if(inDeg[v] == 0) pq.push(-v);
    }
  }
}
int main(){
	FIO;
  int caso = 0;
	while(cin >> n){
    string s;
    for(int i = 0 ; i < n ; i++){
      cin >> s;
      if(id.count(s) == 0) id[s] = id.size(), ar[id[s]] = s;
    }
    cin >> m;
    string x,y;
    for(int i = 0 ; i < m ; i++){
      cin >> x >> y;
      adj[id[x]].pb(id[y]);
      inDeg[id[y]]++;
    }
    topological();
    cout << "Case #" << ++caso <<": Dilbert should drink beverages in this order: "; 
    for(int i = 0 ; i < ans.size() ; i++){
      if(i) cout << " ";
      cout << ar[ans[i]];
      if(i==ans.size()-1) cout << ".";
    }
    cout << "\n\n";
    for(int i = 0 ; i < n ; i++) adj[i].clear();
    id.clear();
    ans.clear();
  }
	return 0;
}