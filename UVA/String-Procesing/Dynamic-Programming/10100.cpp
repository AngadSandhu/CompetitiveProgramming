#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
vector<string> s,t;
int dp[N][N];

void solve(){
  memset(dp,0,sizeof dp);
  for(int i = s.size()-1 ; i >= 0 ; i--){
    for(int j = t.size()-1 ; j >= 0 ; j--){
      if(s[i] == t[j]){
        dp[i][j] = 1 + dp[i+1][j+1];
      }else{
        dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
      }
    }
  }
}
bool myGetline(vector<string> &x){
  string line,aux;
  getline(cin,line);
  bool blank = 1;
  for(int i = 0 ; i < line.size() ; i++){
    if((line[i] >= 'A' && line[i] <= 'Z') 
    || (line[i] >= 'a' && line[i] <= 'z')
    || (line[i] >= '0' && line[i] <= '9')){
      blank = 0;
      continue;
    }
    line[i] = ' ';
  }
  stringstream in(line);
  while(in >> aux) x.pb(aux);
  return blank;
}
int main(){
	FIO;
  int caso = 0;
	while(true){
    bool empty1 = myGetline(s);
    bool empty2 = myGetline(t);
    if(empty1 && empty2) break;
    solve();
    if(empty1 || empty2) printf("%2d. Blank!\n",++caso);
    else printf("%2d. Length of longest match: %d\n",++caso,dp[0][0]);
    s.clear();
    t.clear();
  }
	return 0;
}