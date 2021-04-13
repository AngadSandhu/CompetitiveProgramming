#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
vector<string> s,t;
int dp[N][N],go[N][N];
void rec(int i,int j, bool first){
  if(i >= s.size() || j >= t.size()) return;
  if(go[i][j] == 1){
    if(first == 0) cout << " ";
    cout << s[i];
    rec(i+1,j+1,0);
  }else if(go[i][j] == 2){
    rec(i+1,j,first);
  }else{
    rec(i,j+1,first);
  }
}
void solve(){
  memset(dp,0,sizeof dp);
  memset(go,0,sizeof go);

  for(int i = s.size()-1 ; i >= 0 ; i--){
    for(int j = t.size()-1 ; j >= 0 ; j--){
      if(s[i] == t[j]){
        dp[i][j] = 1 + dp[i+1][j+1];
        go[i][j] = 1;
      }else{
        dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        if(dp[i][j] ==  dp[i+1][j]){
          go[i][j] = 2;
        }else{
          go[i][j] = 3;
        }
      }
    }
  }
  rec(0,0,1);
}

int main(){
	FIO;
	while(true){
    string aux;
    while(cin >> aux){
      if(aux == "#") break;
      s.pb(aux);
    }
    while(cin >> aux){
      if(aux == "#") break;
      t.pb(aux);
    }
    if(s.empty() && t.empty()) break;
    solve();
    s.clear();
    t.clear();
    cout << endl;
  }
	return 0;
}