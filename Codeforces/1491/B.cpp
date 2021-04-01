#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n,u,v; cin >> n >>u >> v;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int maxi = 0;
    for(int i = 1 ; i< n ; i++){
      maxi = max(abs(a[i]-a[i-1]),maxi);
    }
    int ans = 0;
    if(maxi == 0) ans = min(2*v,u+v);
    else if(maxi==1) ans = min(u,v);
    else ans = 0;
    cout << ans << endl; 
  }
	return 0;
}