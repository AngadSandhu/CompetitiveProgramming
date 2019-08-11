#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int m,d,ans,n;
string a,b,s;
int memo[2005][2005][2];
int dp(int pos,int r,bool menor){
	if(memo[pos][r][menor]!=-1) return memo[pos][r][menor];
	if(pos==n) return r==0;
	int ret = 0;
	if(menor){
		if(pos%2){
			ret += dp(pos+1,(r*(10%m)+d%m)%m,1);
			ret%=mod;
		}else{
			for(int i = 0 ; i < 10; i ++){
				if(i!=d) ret += dp(pos+1,(r*(10%m)+i%m)%m,1);
				ret%=mod;
			}
		}
	}else{
		if(pos%2){
			if(s[pos]-'0'< d) ret = 0;
			if(s[pos]-'0'== d) ret += dp(pos+1,(r*(10%m)+d%m)%m,0);
			if(s[pos]-'0'> d) ret += dp(pos+1,(r*(10%m)+d%m)%m,1);
			ret%=mod;
		}else{
			for(int i =0 ; i < s[pos]-'0' ;i++){
				if(i!=d) ret += dp(pos+1,(r*(10%m)+i%m)%m,1);
				ret%=mod;
			}
			if(s[pos]-'0'!=d) ret += dp(pos+1,(r*(10%m)+(s[pos]-'0')%m)%m,0);
			ret%=mod;
		}
	}
	ret%=mod;
	return memo[pos][r][menor] = ret;
}
int main(){
	cin >> m >> d;
	cin >> a >> b;
	for(int i = a.size()-1; i >=0 ;i--){
		if(a[i]=='0') a[i] = '9';
		else { a[i]--; break; }
	}
	memset(memo,-1,sizeof memo);
	s=b; n = s.size();
	ans = dp(0,0,0);
	//cout << ans << endl;
	memset(memo,-1,sizeof memo);
	s=a; n = s.size();
	ans -= dp(0,0,0);
	cout << (ans+mod)%mod << endl;
	return 0;
}
