#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 105
int dr[] = {0,1,1,1,0,-1,-1,-1}, dc[] = {1,1,0,-1,-1,-1,0,1};
int n;
char ar[N][N];
pair<int,int> f(string s, int r,int c){
	for(int i = 0 ; i < 8 ; i++){
		int j;
		int nr = r, nc = c;
		for(j = 0 ; j < s.size() ; j++){
			if(j>0) nr += dr[i], nc += dc[i];
			if(nr < 0 || nc < 0 || nr >= n || nc >= n) break;
			if(s[j] != ar[nr][nc]) break;
		}
		if(j == s.size()) return {nr+1,nc+1};
	}
	return {-1,-1};
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> ar[i][j];
		}
	}
	string s;
	while(cin >> s){
		if(s=="0") break;
		pair<int,int> res = {-1,-1};
		int i, j;
		for( i = 0 ; i < n ; i++){
			for( j = 0 ; j < n ; j++){
				res = f(s,i,j);
				if(res.first != -1) break;
			}
			if(res.first != -1) break;
		}
		if(res.first==-1) cout << "Not found\n";
		else cout << i+1 << "," << j+1 << " " << res.first << "," << res.second << endl;
	}
	return 0;
}
