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
    int n; cin >> n;
    vector<ll> a(n),pre(n+1);
    pre[0] = 0;
    for(int i = 0 ; i < n ; i++){
      cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++){
      pre[i] = pre[i-1] + a[i-1];
    }
    bool ans = 1;
    for(ll i = 0 ; i < n ; i++){
      if(max(0ll,pre[i] - i*(i-1)/2) + a[i] < i){
        ans = 0;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
	return 0;
}