#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 400005
const int mod = 1e9 + 7;
int a[N];
bool vis[N];
void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  dfs(a[u]);
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> x(n),y(n);
    for(int &i: x) cin >> i;
    for(int &i: y) cin >> i;
    for(int i = 0 ; i < n ; i++){
      a[x[i]] = y[i];
    }
    int cmp = 0;
    for(int i = 1 ; i <= n ; i++){
      if(vis[i] == 0){
        cmp++;
        dfs(i);
      }
    }
    // cout << "cmp: " << cmp << endl;
    ll ans = 1;
    for(int i = 0 ; i < cmp ; i++) ans *= 2, ans %= mod;
    cout << ans << endl;
    memset(vis,0,sizeof vis);
  }
	return 0;
}