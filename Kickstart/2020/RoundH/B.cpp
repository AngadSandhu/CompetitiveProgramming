#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll P[19];

ll solveOne(string s){
  ll ans = 0;
  int n = s.size()-1;
  for(int i = 0 ; i < n ; i++) ans += P[i+1];
  return ans;
}
ll solveTwo(string s){
  ll ans = 0;
  int n = s.size();
  for(ll i = 0 ; i < n ; i++){
    ll c = s[i]-'0';
    if(i%2) ans += ((c+1)/2)*P[n-i-1];
    else ans += (c/2)*P[n-i-1];
    if(c%2 != (i+1)%2) break;
  }
  return ans;
}
ll solve(string s){return solveOne(s)+solveTwo(s);}
int main(){
	FIO;
  ll p = 1;
  for(int i = 0 ; i < 19 ; i++){
    P[i] = p;
    p *= 5;
  }
	int t; cin >> t;
  int caso = 1;
  while(t--){
    ll l,r; cin >> l >> r;
    ll ans = solve(to_string(r+1)) - solve(to_string(l));
    cout << "Case #" << caso++ << ": " << ans << endl;
  }
	return 0;
}