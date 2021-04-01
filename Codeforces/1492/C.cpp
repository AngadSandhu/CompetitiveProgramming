#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n,m;
string s,t;

int main(){
	FIO;
  cin >> n >> m >> s >> t;
  vector<int> v1,v2;
  int posm = m-1;
  for(int i = n-1 ; i>=0 && posm >= 0; i--){
    if(s[i] == t[posm]){
      v2.pb(i);
      posm--;
    }
  }
  int ans = 0;
  posm = 0;
  for(int i = 0 ; i < n && posm < m; i++){
    if(s[i] == t[posm]){
      v1.pb(i);
      v2.pop_back();
      posm++;
    }
    if(!v1.empty() && !v2.empty()) ans = max(ans,v2.back()-v1.back());
  }
  cout << ans << endl;
	return 0;
}