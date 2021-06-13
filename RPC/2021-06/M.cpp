#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
char a[N][N];
int n,m,k;
int dr[] = {1,-1,0,0,-1,1,-1,1};
int dc[] = {0, 0, 1,-1,-1,-1,1,1};
int d[N][N];
void bfs(){
	queue<pair<int,int>> q;
	pair<int,int> u;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			d[i][j] = INT_MAX;
  for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
      if(a[i][j] == '#'){
        pair<int,int> s = make_pair(i,j);
        d[s.first][s.second] = 0;
	      q.push(s);
      }
    }
  }
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0 ; i < 8 ; i++){
			int nr = u.first + dr[i];
			int nc = u.second + dc[i];
			if(nr>=0 && nr<n && nc>=0 && nc<m)
				if(d[nr][nc]==INT_MAX){
					d[nr][nc] = d[u.first][u.second] + 1;
					q.push(make_pair(nr,nc));
				}
		}
	}	
	return;
}
int main(){
  FIO;
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      char c;
      cin >> c;
      a[n][m] = c;
    }
  }
  bfs();
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(d[i][j] <= k) cnt++;
    }
  }
  cout << cnt << endl;
	return 0;
}