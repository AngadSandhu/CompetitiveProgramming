#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int n, m;
char a[N][N];
int d[N][N];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
void bfs(pair<int,int> s){
	queue<pair<int,int>>q;
	d[s.first][s.second] = 0;
	q.push(s);
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nr = u.first + dr[i];
			int nc = u.second + dc[i];
			if(nr >=0 && nr < n && nc >= 0 && nc < m){
				if(d[nr][nc] == -1 && a[u.first][u.second] != 'T'){
					q.push(make_pair(nr,nc));
					d[nr][nc] = d[u.first][u.second] + 1;
				}
			}
		}
	}
}
int main(){
	FIO;
  memset(d,-1,sizeof d);
	cin >> n >> m;
  pair<int,int> source, man;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      cin >> a[i][j];
      if(a[i][j] == 'E') source = {i,j};
      if(a[i][j] == 'S') man = {i,j};
    }
  }
  bfs(source);
  int D = d[man.first][man.second];
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      //cout << d[i][j] << " ";
      if(d[i][j] <= D && d[i][j] != -1 && a[i][j] >= '0' && a[i][j] <= '9') ans += a[i][j]-'0';
    }
    //cout << endl;
  }
  cout << ans << endl;
	return 0;
}