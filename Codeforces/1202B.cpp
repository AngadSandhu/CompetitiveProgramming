#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;
 
string s;
int n;
int d[15][15][15][15];
void dp(int x,int y,int c,int f){
	int mini = INT_MAX;
	for(int i = 0 ; i <= 10 ; i++){
		for(int j = 0 ; j <= 10 ; j++){
			if(i==0&&j==0)continue;
			if((c+i*x+j*y)%10==f) mini = min(mini,i+j);
		}
	}
	d[x][y][c][f] = (mini==INT_MAX)?-1:mini;
}
 
int main(){
	cin >> s;
	n = s.size();	
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			for(int k = 0 ; k < 10 ; k++){
				for(int l = 0 ; l < 10 ; l++){
					dp(i,j,k,l);
				}
			}
		}
	}
	
	int ans = 0;
	bool p = 1;
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			ans = 0; p = 1;
			for(int k = 0 ; k < n-1 && p; k++){
				if(d[i][j][s[k]-'0'][s[k+1]-'0']==-1) p = 0;
				ans += d[i][j][s[k]-'0'][s[k+1]-'0']-1;
			}
			cout << (p?(ans):-1) << " ";
		}
		cout << endl;
	}
	return 0;
}
