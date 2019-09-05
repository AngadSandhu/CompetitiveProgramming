#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mp make_pair

using namespace std;
typedef long long ll;

ll memo[20][(1<<10)][(1<<10)][2];
string s;
int n;
ll a, b;

bool f(int mask,int on){
	for(int i = 0 ; i < 10 ; i ++){
		if((on>>i)&1==0) continue;
		if((mask>>i)&1 == i%2) return false;
	}
	return true;
}
ll dp(int pos,int mask,int on, bool menor){
	if(memo[pos][mask][on][menor]!=-1) return memo[pos][mask][on][menor];
	if(pos==n) return memo[pos][mask][on][menor] = f(mask,on);
	ll ret = 0;
	if(menor){
		for(int i = 0; i < 10 ; i++){
			ret += dp(pos+1,mask^(1<<i),on|(1<<i),1);
		}
	}else{
		for(int i = 0 ; i < s[pos]-'0'; i++){
			ret += dp(pos+1,mask^(1<<i),on|(1<<i),1);
		}
		
		ret += dp(pos+1,mask^(1<<(s[pos]-'0')),on|(1<<(s[pos]-'0')),0);
	}
	return memo[pos][mask][on][menor] = ret;
}

int main(){
	int t;cin >>t;
	while(t--){
		cin >> a >> b ; a--;
		
		memset(memo,-1,sizeof memo);
		s = to_string(b);
		n = s.size();
		ll res = dp(0,0,0,0);
		
		memset(memo,-1,sizeof memo);
		s = to_string(a);
		n = s.size();
		res -= dp(0,0,0,0);
		
		
		cout << res << endl;
	}
	return 0;
}
