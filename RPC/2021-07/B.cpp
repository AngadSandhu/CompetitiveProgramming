#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define N 11
#define FIFO ios::sync_with_stdio(false)
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)
#define MOD 1000000007
#define ones(x) __builtin_popcountll(x)

using namespace std;

char T[N][N];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool visited[N][N][9][101][102];
int r, c;

bool valid(int _r, int _c){ return _r >= 0 && _r < r && _c >= 0 && _c < c; }
string s;

void DFS(int row, int col, int lastDir, int pos, int steps){
	
	visited[row][col][lastDir][pos][steps] = true;
	if(pos == s.size() - 1)return;

	for(int l = 0; l < 8; l++){
		
		int _r = row + dx[l];
		int _c = col + dy[l];
		int _steps = steps + (lastDir != l);
		
		if(!valid(_r, _c) || visited[_r][_c][l][pos + 1][_steps] || s[pos + 1] != T[_r][_c])continue;
		DFS(_r, _c, l, pos + 1, _steps);
	}
}


int main(){

	FIFO;

	int k;
	cin >> r >> c;
	
	set<char>st;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)cin >> T[i][j], st.insert(T[i][j]);
		
	
	cin >> k;
	cin >> s;
	
	if(s.size() == 1){
		
		if(st.find(s[0]) != st.end() && k == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else{
		
		int n = s.size();
		
		bool ok = false;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				for(int l = 0; l < 8; l++){
					
					int _i = i + dx[l];
					int _j = j + dy[l];
					
					if(!valid(_i, _j))continue;
					if(T[i][j] == s[0] && T[_i][_j] == s[1] && !visited[_i][_j][l][1][1])DFS(_i, _j, l, 1, 1);
					
				}
			}
		}
			
		if(k < s.size()){
			
			for(int i = 0; i < r && !ok; i++){
				for(int j = 0; j < c && !ok; j++){
					for(int l = 0; l < 8 && !ok; l++)if(visited[i][j][l][n - 1][k + 1])ok = true;
				}
			}
		}
		
		if(ok)cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}

