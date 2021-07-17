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
    vector<int> a(n), b,c;
    for(int &i : a){
      cin >> i;
      if(i%2 == 0) b.pb(i);
      else c.pb(i); 
    }
    a.clear();
    for(int i = 0 ; i < b.size() ; i++){
      a.pb(b[i]);
    }
    for(int i = 0 ; i < c.size() ; i++){
      a.pb(c[i]);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      for(int j = i+1 ; j < n ; j++){
        if(__gcd(a[i],2*a[j]) > 1) ans++;
      }
    }
    cout << ans << endl;
  }
	return 0;
}