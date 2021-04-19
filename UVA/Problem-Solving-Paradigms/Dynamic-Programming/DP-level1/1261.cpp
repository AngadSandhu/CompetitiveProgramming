#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
map<string,bool> ok;
bool solve(string s){
  if(ok.find(s) != ok.end()) return ok[s];
  int n = s.size();
  int i = 0;
  while(i < n){
    int j = i;
    while(j < n && s[j] == s[i]) j++;
    if(j-i >= 2){
      string t = s.substr(0,i) + s.substr(j);
      bool res = solve(t);
      if(res){
        ok[s] = 1;
        return 1;
      }
    }
    i = j;
  }
  ok[s] = 0;
  return 0;
}
int main(){
	FIO;
  ok[""] = 1;
	int t; cin >> t;
  while(t--){
    string s; cin >> s;
    cout << solve(s) << endl;
  }
	return 0;
}