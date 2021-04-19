#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 35
#define M 25
#define INF 100000000
int n,t1,t2;
int m[N];
int c[2][N][M];
int memo[N][305][305];
int recon[N][305][305];
int dp(int pos,int c1,int c2){
  if(pos == n){
    if(c1 == t1 && c2 == t2) return 0;
    else return INF;
  }
  int &ret = memo[pos][c1][c2];
  if(ret != -1) return ret;
  int ans = INF;
  for(int i = 0 ; i <= m[pos] ; i++){
    int j = m[pos] - i;
    int curr = c[0][pos][i] + dp(pos+1,c1 + i, c2 + j) + c[1][pos][j];
    if(ans > curr){
      ans = curr;
      recon[pos][c1][c2] = i;
    }
  }
  return ret = ans;

}
vector<int> sol;
void rec(int pos,int c1,int c2){
  if(pos == n) return;
  int i = recon[pos][c1][c2];
  sol.pb(i);
  rec(pos+1,c1 + i,c2 + m[pos]-i);
}

int main(){
	FIO;
  while(cin >> t1 >> t2){
    if(t1 == 0 && t2 == 0) break;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
      cin >> m[i];
      for(int j = 1 ; j <= m[i] ; j++){
        cin >> c[0][i][j];
      }
      for(int j = 1 ; j <= m[i] ; j++){
        cin >> c[1][i][j];
      }
      c[0][i][0] = c[1][i][0] = 0;
    }
    memset(memo,-1,sizeof memo);
    cout << dp(0,0,0) << endl;
    rec(0,0,0);
    for(int i = 0 ; i < sol.size() ; i++){
      if(i) cout << " ";
      cout << sol[i];
    }
    cout << endl;
    cout << endl;
    sol.clear();
  }
	return 0;
}