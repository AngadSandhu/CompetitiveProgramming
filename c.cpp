#include<bits/stdc++.h>
using namespace std;
#define N 200005
typedef long long ll;
int n,m;
int used[10][10];
int res;
 
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int x,y; cin >> x >> y;
		used[--x][--y] = used[y][x] = 1;
	}
	if(n<7) res = m;
	else{
		int mx = -1;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
			if(i==j) continue;
			int cant =0 ;
				for(int k = 0 ; k < n ; k++){
					for(int l = 0 ; l < n ; l++){
						if(k==i||k==j) continue;
						cant += used[k][l]; 
					}
				}
				for(int k = 0 ; k < n ; k++){
					cant+= (used[i][k]||used[j][k]);
				}
				mx = max(cant/2,mx);
			}
		}
		res = mx;
	}
	cout << res << endl;
	return 0;
}
