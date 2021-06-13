#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
string build(ll x,int n){
  string ret = "";
  while(ret.size() < n){
    ret += to_string(x);
    x++;
  }
  return ret;
}
bool comp(string s1, string s2){
  if(s1.size() == s2.size()) return s1 < s2;
  else return s1.size() < s2.size();
}
int main(){
	FIO;
	int t; cin >> t;
  int caso  = 0;
  while(t--){
    string s; cin >> s;
    string ans = "???????????????????????????";
    ll curr = 0;
    string scurr = "";
    for(int i = 0 ; i < s.size()-1 ; i++){
      curr = stoll(s.substr(0,i+1));
      if(stoll(build(curr,s.size())) > stoll(s)) ans = min(ans,build(curr,s.size()),comp);
      if(stoll(build(curr+1,s.size())) > stoll(s)) ans = min(ans,build(curr+1,s.size()),comp);
      // cout << i << " " << build(curr,s.size()) << endl;
    }
    if(s.size() == 1) ans = to_string(stoll(s) + 1);
    cout << "Case #" << ++caso <<": " << ans << endl;
  }
	return 0;
}