#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000006

ll ar[N];

vector<ll> arUni;

int main(){
	FIO;
  ll n,m,a,c,x0;
  cin >> n >> m >> a >> c >> x0;
  ar[0] = (a*x0+c)%m;
  arUni.pb(ar[0]);
  for(int i = 1 ; i < n ; i++) ar[i] = (a*ar[i-1]+c)%m, arUni.pb(ar[i]);
  arUni.resize(unique(arUni.begin(), arUni.end())-arUni.begin());
  //for(auto x : arUni) cout << x << endl;
  ll ans= 0 ;
  for(auto look: arUni){
    ll l = 0, r = n-1 , med;
    while(l<r){
      med=(l+r)/2;
      //cout << l << " " << r << " " << look << " " << ar[med] << endl;
      if(ar[med] == look){
        ans++;
        break;
      }
      if(look < ar[med]){
        r = med-1;
      }else{
        l = med+1;
      }
    }
    if(l==r && ar[l]==look) ans++;
  }
  cout << ans << endl;
	return 0;
}