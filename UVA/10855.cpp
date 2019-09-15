#include<bits/stdc++.h>
using namespace std;
int n,m; 
char a[1005][1005], b[1005][1005];
bool check(int r,int c){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[r+i][c+j]!=b[i][j]) return false;
		}
	}
	return true;
}
void rot(){
	char c[1005][1005];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			c[j][m-1-i] = b[i][j];
		}
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			b[i][j] = c[i][j];
		}
	}
}
int main(){
	while(cin >> n >>m, n > 0){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> b[i][j];
			}
		}
		
		int res = 0;
		for(int k = 0 ; k < 4 ; k ++){
			res = 0;
			for(int i = 0 ; i <= n-m ; i++){
				for(int j = 0 ; j <= n-m ; j++){
					res += check(i,j);
				}
			}
			cout << res;
			if(k!=3) cout << " ";
			rot();
		}
		cout << endl;
	}
	return 0;
}
