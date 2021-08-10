#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
ll st[N][25];
int n;
int getMax(int p){
  int i = p;
  ll g = 0;
  for(int j = 20 ; j >= 0 ; j--){
    if(i + (1<<j) > n || __gcd(g,st[i][j]) <= 1) continue;
    g = __gcd(g,st[i][j]);
    i += (1<<j);
  }
  return i-p;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n;
    vector<ll> a(n),d(n+1,0);
    for(ll &i: a) cin >> i;
    for(int i = 1 ; i < n ; i++){
      d[i] = abs(a[i] - a[i-1]);
    }
    for(int i = 1 ; i <= n ; i++){
      st[i][0] = d[i];
    }
    for(int j = 1 ; j < 20 ; j++){
      for(int i = 1 ; i + (1<<j) <= n ; i++){
        st[i][j] = __gcd(st[i][j-1],st[i + (1<<(j-1))][j-1]);
      }
    }
    int ans = 1;
    for(int i = 1 ; i < n ; i++) ans = max(ans,getMax(i)+1);
    cout << ans << endl;
    for(int i = 0 ; i <= n ; i++){
      for(int j = 0 ; j < 25 ; j++){
        st[i][j] = 0;
      }
    }
  }
	return 0;
}