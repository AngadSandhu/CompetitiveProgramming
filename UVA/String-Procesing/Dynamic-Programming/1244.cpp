#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 55
char mat[N][N];
string memo[N][N];
pair<int,int> go[N][N];
vector<pair<char,int>> order[N];
int n; 
string dp(int u, int v){
  if(u >= v)return "";
  string &ret = memo[u][v];
  if(ret != "-") return ret;
  string ans; ans += mat[u][v];
  for(int i = u+1 ; i < v ; i++){
    for(int j = i ; j < v ; j++){
      if(mat[u][i] == mat[j][v]){
        string aux = mat[u][i] + dp(i,j) + mat[j][v];
        if(ans.size() <= aux.size()){
          if(ans.size() == aux.size()) ans = min(ans,aux);
          else ans = aux;
        }
      }
    }
  }
  return ret = ans;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0 ; i <= n  ; i++){
      for(int j = 0 ; j <= n ; j++){
        memo[i][j] = "-";
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        cin >> mat[i][j];
      }
    }
    cout << dp(0,n-1) << endl;
  }
	return 0;
}