#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
char s[4][N];
ll dp[N][N][N][N];
int last[4][30];
int n[4];
ll res = 0;
int main(){
	scanf("%s %s %s %s",s[0]+1,s[1]+1,s[2]+1,s[3]+1);
	for(int i = 0 ; i < 4; i++) n[i] = strlen(s[i]+1), s[i][0] = '.';
	for(int i = n[0]; i > 0 ; i--){
		fill(last[1],last[1]+30,0);
		for(int j = n[1]; j > 0 ; j--){
			fill(last[2],last[2]+30,0);
			for(int k = n[2]; k > 0 ; k--){
				fill(last[3],last[3]+30,0);
				for(int l = n[3]; l > 0 ; l--){
					dp[i][j][k][l] = (s[0][i]==s[1][j] && s[1][j]==s[2][k] && s[2][k]==s[3][l]) ? 1:0; 
					for(int m = 0 ; m < 27 ; m++){
						if(last[0][m]==0 || last[1][m]==0 || last[2][m] == 0 || last[3][m] == 0) continue;
						dp[i][j][k][l] += dp[last[0][m]][last[1][m]][last[2][m]][last[3][m]];
					}
					last[3][s[3][l]-'a'] = l;
				}
				last[2][s[2][k]-'a'] = k;
			}
			last[1][s[1][j]-'a'] = j;
		}
		last[0][s[0][i]-'a'] = i;
	}
	
	for(int m = 0 ; m < 27 ; m++){
		if(last[0][m]==0 || last[1][m]==0 || last[2][m] == 0 || last[3][m] == 0) continue;
		res += dp[last[0][m]][last[1][m]][last[2][m]][last[3][m]];
		
	}
	cout << res << endl;
	return 0;
}
