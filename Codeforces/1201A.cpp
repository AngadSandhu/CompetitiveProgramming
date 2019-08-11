#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1005][30];
int main(){
cin >> n >> m;
string s;
	for(int i = 0 ; i < n ;i++){
		cin >> s;
		for(int j = 0 ; j < m ; j++){
			f[j][s[j]-'A']++;
		}
	}
	int maxi = -1,ans = 0,score; 
	for(int i = 0 ; i < m ;i++){
	maxi = -1;
		for(int j = 0 ; j < 30 ; j++){
			maxi = max(maxi,f[i][j]);
		}
		cin >> score;
		ans += score*maxi;
	}
	cout << ans << endl;
	return 0;
}
