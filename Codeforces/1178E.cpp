#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int first[N][3],last[N][3];
int n;
char s[N];
int main(){
	scanf("%s",s+1);
	s[0] = '.';
	n = strlen(s);
	int saw[3] = {};
	for(int i = n-1 ; i > 0 ; i--){
		saw[s[i]-'a'] = i;
		for(int j = 0 ; j < 3; j ++) first[i][j] = saw[j];
	}
	memset(saw,0,sizeof saw);
	for(int i = 1 ; i < n ; i++){
		saw[s[i]-'a'] = i;
		for(int j = 0 ; j < 3; j ++) last[i][j] = saw[j];
	}
	vector<int>res1,res2;
	int l = 1, r =n-1,ll,rr,maxi, maxilet;
	while(l<r){
		maxi = INT_MIN;
		for(int i = 0 ; i < 3 ; i++){
			if(last[r][i]==0 || first[l][i]==0 || first[l][i]>r || last[r][i]<l) continue;
			if(maxi<last[r][i]-first[l][i]){
				maxi = last[r][i]-first[l][i];
				maxilet = i;
				ll = first[l][i]+1;
				rr = last[r][i]-1;
			}
		}
		l = ll;
		r = rr;
		res1.push_back(maxilet);
		if(maxi!=0) res2.push_back(maxilet);
	}
	for(auto v : res1) cout << char(v+'a');
	for(int i = res2.size()-1 ; i>=0 ; i--) cout << char(res2[i]+'a');
	cout << endl;
	return 0;
}
