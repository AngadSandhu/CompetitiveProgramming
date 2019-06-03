#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int p[4][100][100];
	int c[200][200];
	string s;
	getline(cin,s);
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < n ; j++){
			getline(cin,s);
			for(int k = 0 ; k < n ; k++){
				p[i][j][k] = s[k] - '0';
			}
		}
		getline(cin,s);
	}
	int num[] = {0,1,2,3};
	int c1 = 0, c2 = 0,r,m = 99999;
	vector<int>g[2];
	do{
		c1 = 0; c2 = 0; g[0].clear(); g[1].clear();
		for(int i = 0 ; i < 2*n ; i++){
			for(int j = 0 ; j < 2*n ; j++){
				if(i >= n){
					if(j >= n) c[i][j] = p[num[3]][i%n][j%n];
					else c[i][j] = p[num[1]][i%n][j%n];
				}else{
					if(j >= n) c[i][j] = p[num[2]][i%n][j%n];
					else c[i][j] = p[num[0]][i%n][j%n];
				}
			}
		}
		
		for(int i = 0 ; i < 2*n ; i++){
			for(int j = 0 ; j < 2*n ; j++){
				if((j+i) % 2 == 0) g[0].push_back(c[i][j]);
				else g[1].push_back(c[i][j]);
			}
		}
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < g[0].size(); j++){
				if(!i && g[0][j]) c1++;
				if(i && g[1][j]) c2++;
			}
		}
		if(c1 > c2) r = (g[0].size()-c1) + c2;
		else r = (g[1].size()-c2) + c1;
		m = min(r,m);

	}while(next_permutation(num,num+4));
	cout << m << endl;
	
	return 0;
}
