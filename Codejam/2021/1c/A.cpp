#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  int caso = 0;
  while(t--){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(),a.end());
    vector<int> b;
    for(int i = 1 ; i < a.size() ; i++){
      b.pb(max(a[i]-a[i-1]-1,0));
    }
    sort(b.begin(),b.end());
    cout << "Case #" << ++caso << ": ";
    int ans = 0;
    if(n > 2) ans = max((b[b.size()-1]+1)/2 + (b[b.size()-2]+1)/2, b[b.size()-1]);
    if(n > 1){
      ans = max(ans,b[b.size()-1]);
      ans = max(ans,a[0]-1 + (b[b.size()-1]+1)/2);
      ans = max(ans,k-a[n-1] + (b[b.size()-1]+1)/2);
    }
    ans = max(ans,a[0]-1 + k-a[n-1]);
    cout << fixed << setprecision(6) << 1.0*ans/k << endl;
  }
	return 0;
}