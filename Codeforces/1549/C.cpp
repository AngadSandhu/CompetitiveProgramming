#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
unordered_map<int,int> bigger;
int main(){
	FIO;
	int n,m; cin >> n >> m;
  int u,v;
  for(int i = 0 ; i < m ; i++){
    cin >> u >> v; u--,v--;
    if(u > v) swap(u,v);
    bigger[u]++;
  }
  int q; cin >> q;
  while(q--){
    int id; cin >> id;
    if(id == 1){
      cin >> u >> v; u--,v--;
      if(u > v) swap(u,v);
      bigger[u]++;
    }
    if(id == 2){
      cin >> u >> v; u--,v--;
      if(u > v) swap(u,v);
      bigger[u]--;
      if(bigger[u] == 0) bigger.erase(u);
    }
    if(id == 3){
      cout << n - bigger.size() << endl;
    }
  }
	return 0;
}