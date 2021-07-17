#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 25 
int a[N][N];
int dr[] = {0,1,1,1,0,-1,-1,-1}, dc[] = {1,1,0,-1,-1,-1,0,1};
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n,m; cin >> n >> m;
    int ans = 0, curr =0;
    
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        a[i][j] = (i+j)%2 ? 0 : 1;
      }
    }
    
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(!(i == 0 || i == n-1 || j == 0 || j == m-1)) a[i][j] = 0;
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        for(int k = 0 ; k < 8 ; k++){
          int nr = i + dr[k], nc = j + dc[k];
          if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
          if(a[nr][nc] == 1) a[i][j] = 0;
        }
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        curr += a[i][j];
      }
    }
    curr = 0;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        a[i][j] = (i+j)%2 ? 1 : 0;
      }
    }
    
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(!(i == 0 || i == n-1 || j == 0 || j == m-1)) a[i][j] = 0;
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        for(int k = 0 ; k < 8 ; k++){
          int nr = i + dr[k], nc = j + dc[k];
          if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
          if(a[nr][nc] == 1) a[i][j] = 0;
        }
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        ans += a[i][j];
      }
    }
    if(ans < curr){
      for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        a[i][j] = (i+j)%2 ? 0 : 1;
      }
    }
    }
     for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cout << a[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
	return 0;
}