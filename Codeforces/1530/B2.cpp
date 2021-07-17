#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 25
int a[N][N];
int b[N][N];
int dr[] = {0,1,1,1,0,-1,-1,-1}, dc[] = {1,1,0,-1,-1,-1,0,1};
int main(){
	FIO;
  int t; cin >> t;
  while(t--){
    int n,m; cin >> n >> m;
    int ans = 0;
    for(int i = 0 ; i < (1<<3) ; i++){
      int curr = 0;
      memset(a,-1,sizeof a);
      if(__builtin_popcount(i) != 1) continue;
      a[0][0] = i&1;
      a[0][1] = (i>>1)&1;
      a[1][0] = (i>>2)&1;
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
          for(int k = 0 ; k < 8 ; k++){
            int nr = i + dr[k], nc = j + dc[k];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(a[nr][nc] == 1) a[i][j] = 0;
          }
          if(a[i][j] == -1){
            if(i == 0 || i == n-1 || j == 0 || j == m-1) a[i][j] = 1;
            else a[i][j] = 0;
          }
        }
      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
          curr += a[i][j];
        }
      }
      if(curr > ans){
        ans = curr;
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            b[i][j] = a[i][j];
          }
        }
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cout << b[i][j];
      }
      cout << endl;
    }
    cout <<endl;
  }
	return 0;
}