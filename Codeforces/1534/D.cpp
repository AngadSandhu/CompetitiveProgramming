#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 2005
void ask(int x){
  cout << "? " << x << endl;
}
vector<int> adj[N];
bool ans[N][N];
bool bip[N];
int main(){
	FIO;
  int n; cin >> n;
  ask(1);
  int par = 0,impar = 0;
  bool choose = 0;
  for(int i = 0 ; i < n ; i++){
    int d; cin >> d;
    if(i==0) continue;
    if(d%2) bip[i] = 1,impar++;
    else bip[i] = 0, par++;
    if(d == 1) adj[0].pb(i);
  }
  if(par < impar) choose = 0;
  else choose = 1;
  vector<int> toAsk;
  for(int i = 1 ; i < n ; i++){
    if(bip[i] == choose) toAsk.pb(i);
  }
  for(int i = 0 ; i < toAsk.size() ; i++){
    ask(toAsk[i] + 1);
    for(int j = 0 ; j < n ; j++){
      int d; cin >> d;
      if(d == 1) adj[toAsk[i]].pb(j);
    }
  }
  cout << "!\n";
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < adj[i].size() ; j++){
      ans[min(i,adj[i][j])][max(i,adj[i][j])] = 1;
    }
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
      if(ans[i][j] == 1) cout << i+1 << " " << j+1 << endl;
    }
  }
	return 0;
}