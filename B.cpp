#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1005][1005];
char mapa[1005][1005];
bool graph[1005][1005];
int d[1005][1005];
bool mar[1005];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[] = {1, 0, -1, 1, -1, 1,0,-1};
int id=0;
void pintar(int r,int c){
	if(mapa[r][c]=='O') mar[id] = true;
	a[r][c] = id;
	for(int i = 0 ; i < 8 ; i++){
		int nr = r + dr[i], nc = c + dc[i];
		if(nr < 0|| nr>=n || nc < 0 ||nc >= m) continue;
		if(a[nr][nc] == -1 && mapa[r][c] == mapa[nr][nc]) pintar(nr,nc);
		if(a[r][c] != -1) 
			graph[id][a[r][c]] = graph[a[r][c]][id] = true;
	}
}

int bfs(int src,int meta){
	queue<int> q;
	q.push(src);
	d[src][src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0 ; i < id ; i++){
			if(graph[u][i] && d[src][i] == -1){
				q.push(i);
				d[src][i] = d[src][u] + !mar[i];
			}
		}
	}
	return d[src][meta];
}
 
int main(){
	memset(d,-1,sizeof d);
	cin >> n >> m >> q;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> mapa[i][j]; a[i][j] = -1;
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ;j++){
			if(a[i][j]==-1) pintar(i,j), id++;
		}
	}
	
	cout << endl;	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ;j++){
			cout << a[i][j] ;
		}
		cout << endl;
	}	
	
	
	int r1,c1,r2,c2;
	while(q--){
	cout << "hola"<< endl;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << bfs(a[r1-1][c1-1],a[r2-1][c2-1]) << endl;		
	}		
	return 0;
}

