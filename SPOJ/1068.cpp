#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
typedef long long ll;
using namespace std;
 
string s;
int a,b,k,ans,n;
int memo[15][100][100][2];

int dp(int pos,int r,int sum, bool f){
	if(memo[pos][r][sum][f] !=-1) return memo[pos][r][sum][f];
	if(pos==n) return (r==0 && sum%k==0);
	int ret = 0;
	if(f){
		for(int i = 0 ;i < 10; i++){
			ret += dp(pos+1,(r*(10%k)+i)%k,sum+i,1);
		}
	}else{
		for(int i = 0 ;i < (s[pos]-'0') ; i++){
			ret += dp(pos+1,(r*(10%k)+i)%k,sum+i,1);
		}
		ret += dp(pos+1,(r*(10%k)+(s[pos]-'0'))%k,sum+(s[pos]-'0'),0);
	}
	return memo[pos][r][sum][f] = ret;
}

int main(){
	int t;cin >> t;
	int p = 0;
	while(t--){
		p++;
		cin >> a>> b >> k; a--; 
		if(k<100){
			memset(memo,-1,sizeof memo);
			s = to_string(b); n = s.size();
			ans = dp(0,0,0,0);
			memset(memo,-1,sizeof memo);
			s = to_string(a); n = s.size();
			ans -= dp(0,0,0,0);
			printf("Case %d: %d\n",p,ans);
		}else{
			printf("Case %d: %d\n",p,0);		
		}
	}
	return 0;	
}
