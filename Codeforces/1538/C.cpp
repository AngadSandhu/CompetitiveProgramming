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
    int n,l,r; cin >> n >> l >> r;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
      int pos1 = upper_bound(a.begin(),a.begin()+i,r-a[i]) - a.begin();
      int pos2 = lower_bound(a.begin(),a.begin()+i,l-a[i]) - a.begin();
      ans += max(0,pos1-pos2);
      //cout << pos1 << " " << pos2 << endl;
    }
    cout << ans << endl;
  }
	return 0;
}