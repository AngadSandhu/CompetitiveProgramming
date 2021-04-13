#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int p[N],c[N];
int main(){
	FIO;
	int t; cin >> t;
  int caso = 0;
  while(t--){
    int m; cin >> m;
    vector<int> a;
    for(int i = 0 ; i < m ; i++){
      cin >> p[i] >> c[i];
      for(int j = 0; j < c[i] ; j++) a.pb(p[i]);
    }
    int n = a.size();
    ll ans = 0;
    for(int i = 1 ; i < (1<<n)-1 ; i++){
      ll sum = 0, prod = 1;
      for(int j = 0 ; j < n ; j++){
        if((i>>j)&1){
          sum += a[j];
        }else{
          prod *= a[j];
        }
        if(prod > INT_MAX) break;
      }
      if( sum == prod ) ans = max(ans,sum);
    }
    cout << "Case #" << ++caso << ": " << ans << endl;
  }
	return 0;
}