#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
string ar[1005][20000];
int memo[1005][20000];

pair<int,int> getPair(string s){
  int i = 0, j = 0;
  for(int k = 0 ; k < s.size() ; k++){
    if(s[k] >= 'A' && s[k] <= 'Z') j *= 26, j += s[k]-'A'+1;
    if(s[k] >= '0' && s[k] <= '9'){
      i += stoi(s.substr(k));
      break;
    }
  }
  i--,j--;
  return make_pair(i,j);
}

int dp(int r, int c){
  int &ret = memo[r][c];
  if(ret != -1) return ret;
  if(ar[r][c][0] != '=') return stoi(ar[r][c]);
  
  int ans = 0;
  for(int i = 0 ; i < ar[r][c].size() ; i++){
    if(ar[r][c][i] == '=' || ar[r][c][i] == '+') ar[r][c][i] = ' ';
  }
  
  stringstream in(ar[r][c]);
  string aux;
  while(in >> aux){
    pair<int,int> next = getPair(aux);
    // cout <<aux << " " << next.first << " " << next.second << endl;
    ans += dp(next.first,next.second);
  }

  return ret = ans;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n,m; cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cin >> ar[i][j];
      }
    }
    memset(memo,-1,sizeof memo);
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(j) cout << " ";
        cout << dp(i,j);
      }
      cout << endl;
    }
    
  }
	return 0;
}