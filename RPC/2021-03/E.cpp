#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 505
int n,m;
int ar[N][N];
bool vis[N][N];
int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
int bfs(pair<int,int> s){
	queue<pair<int,int>> q;
	vis[s.first][s.second] = 1;
	bool isBest = 1;
	q.push(s);
	while(!q.empty()){
		pair<int,int> v = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nr = v.first + dr[i], nc = v.second + dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if(ar[nr][nc] != ar[s.first][s.second]){
				if(ar[nr][nc] > ar[s.first][s.second]) isBest = 0;
				continue;
			}
			if(vis[nr][nc]) continue;
			vis[nr][nc] = 1;
			q.push(make_pair(nr,nc));
		}
	}
	return isBest && ar[s.first][s.second] > 1;
}
int main(){
	FIO;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) {
			cin >> ar[i][j];
		}
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) {
			if(vis[i][j]==0)
			ans += bfs({i,j});
		}
	}
	cout << ans << endl;
	return 0;
}