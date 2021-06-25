#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int r,c;
char a[N][N];
int d[N][N];
int dr[] = {0, 1, 0, -1}, dc[] = {1,0,-1,0};
void bfs01(){
  for(int i = 0 ; i < r ;  i++){
      for(int j = 0 ; j < c ; j++){
        d[i][j] = (1<<30);
      }
    }
  deque<pair<int,int>> q;
  d[0][0] = 0;
  q.push_back({0,0});
  while(!q.empty()){
    auto u = q.front();
    q.pop_front();
    for(int i = 0; i < 4 ; i++){
      int nr = u.first + dr[i], nc = u.second + dc[i];
      bool w = a[u.first][u.second] != a[nr][nc];

      if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
      if(d[u.first][u.second] + w >= d[nr][nc]) continue;

      d[nr][nc] = d[u.first][u.second] + w;
      if(w) q.push_back({nr,nc});
      else q.push_front({nr,nc});
    }
  }
}
int main(){
	FIO;
	int t; cin >>t;
  while(t--){
    cin >> r >> c;
    for(int i = 0 ; i < r ;  i++){
      for(int j = 0 ; j < c ; j++){
        cin >> a[i][j];
      }
    }
    bfs01();
    cout << d[r-1][c-1] << endl;
  }
	return 0;
}