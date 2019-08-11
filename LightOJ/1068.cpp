#include<bits/stdc++.h>
using namespace std;
int memo[15][10000][10000][2];
int ten[15];
int t,k,ans,aa;
string a,b,s;
int dp(int pos,int rd,int rn,bool f){
	if(memo[pos][rd][rn][f]!=-1) return memo[pos][rd][rn][f];
	if(pos==s.size()) return (rd==0 && rn==0);
	int ret = 0;
	if(f){
		for(int i = 0 ; i < 10 ; i++){
			ret += dp(pos+1,(rd+i)%k,(rn+i*ten[pos])%k,1);
		}
	}else{
		for(int i = 0; i < s[pos]-'0'; i++){
			ret += dp(pos+1,(rd+i)%k,(rn+i*ten[pos])%k,1);
		}
		ret += dp(pos+1,(rd+(s[pos]-'0'))%k,(rn+(s[pos]-'0')*ten[pos])%k,0);
	}
	return memo[pos][rd][rn][f] = ret;
}
int main(){
	cin >> t;
	int tp = 1,p=0;
	while(t--){
		p++;
		cin >> aa >> b >> k; aa--; a = to_string(aa);
		tp = 1;
		memset(memo,-1,sizeof memo);
		for(int i = b.size()-1 ; i>=0 ; i--) ten[i] = tp,tp*=10;
		s = b;
		ans = dp(0,0,0,0);
		
		memset(memo,-1,sizeof memo);
		tp = 1;
		for(int i = a.size()-1 ; i>=0 ; i--) ten[i] = tp,tp*=10;
		s = a;
		ans -= dp(0,0,0,0);
		printf("Case %d: %d\n",p,ans);
	}
	
	return 0;
}
