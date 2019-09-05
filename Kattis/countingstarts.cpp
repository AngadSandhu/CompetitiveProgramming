#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
bool a[105][105];
int dr[4] = {-1,0,0,1}, dc[4] = {0,1,-1,0};

void bfs(int sr,int sc){
	queue<int> qr,qc;
	qr.push(sr);
	qc.push(sc);
	a[sr][sc] = 0;
	while(!qr.empty() && !qc.empty()){
		int ur = qr.front(), uc = qc.front();
		qr.pop(); qc. pop();
		for(int i = 0 ;i < 4 ; i++){
			int nr = ur + dr[i], nc = uc + dc[i];
			if(nr<0 || nc < 0 || nr >= n || nc >= m) continue;
			if(a[nr][nc]==0) continue;
			a[nr][nc] = 0;
			qr.push(nr); qc.push(nc);
		}
	}
}
int main(){
	int p = 0;
	while(cin >>n >> m){
		p++;
		for(int i =0 ; i < n ; i++){
			for(int j =  0 ;j < m ; j++){
				char x;
				cin >> x;
				a[i][j] = (x=='-');
			}
		}
		int c = 0;
		for(int i =0 ; i < n ; i++){
			for(int j =  0 ;j < m ; j++){
				if(a[i][j]==1){
					bfs(i,j);
					c++;
				}
			}
		} 
		printf("Case %d: %d\n",p,c);
	}
}
