#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
const int mod = 998244353;
struct dat{
	int tipo, niv; // 1.# 2.& 3.| 4.^
	dat(){};
	dat(int a,int b){tipo = a, niv = b; };
};
string s;
int n;
vector<dat> ar;
int RMQ[N][20], RMQi[N][20];

void initrmq(){
	for(int i = 0 ; i < n ; i++){
		RMQ[i][0] = ar[i].niv;
		RMQi[i][0] = i;
	}
	for(int j = 1 ; (1<<j) <= n ; j++){
		for(int i = 0 ; i + (1<<j) <= n ; i++){
			if(RMQ[i][j-1] < RMQ[i+(1<<(j-1))][j-1]){
				RMQ[i][j] = RMQ[i][j-1];
				RMQi[i][j] = RMQi[i][j-1];
			}else{
				RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
				RMQi[i][j] = RMQi[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int queryrmq(int l, int r){
	int bit = 31 - __builtin_clz(r-l+1);
	if(RMQ[l][bit] < RMQ[r+1-(1<<bit)][bit]){
		return RMQi[l][bit];
	}else{
		return RMQi[r+1-(1<<bit)][bit];
	}
}
pair<ll,ll> dfs(int v,int l,int r){
	if(ar[v].tipo == 1) return {499122177,499122177};
	pair<ll,ll> LS = dfs(queryrmq(l,v-1),l,v-1);
	pair<ll,ll> RS = dfs(queryrmq(v+1,r),v+1,r);
 	if(ar[v].tipo==2){
		return {(( (LS.first*RS.first)%mod + LS.first*RS.second) %mod+ LS.second*RS.first)%mod,
			(LS.second*RS.second)%mod};
	}
	if(ar[v].tipo==3){
		return {(LS.first*RS.first)%mod,
			(( (LS.first*RS.second)%mod + LS.second*RS.first)%mod + LS.second*RS.second)%mod};
	}
	if(ar[v].tipo==4){
		return {( (LS.first*RS.first)%mod + (LS.second*RS.second)%mod )%mod,
			( (LS.first*RS.second)%mod + (LS.second*RS.first)%mod )%mod};
	}
}
int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		cin >> s;
		int cnt = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '(') cnt++;
			if(s[i] == ')') cnt--;
			if(s[i] == '#') ar.pb(dat(1,cnt+1));
			if(s[i] == '&') ar.pb(dat(2,cnt));
			if(s[i] == '|') ar.pb(dat(3,cnt));
			if(s[i] == '^') ar.pb(dat(4,cnt));
		}
		n = ar.size();
		initrmq();
		pair<ll,ll> ans = dfs(queryrmq(0,n-1),0,n-1);
		cout << (ans.first*ans.first)%mod << " " << (ans.second*ans.second)%mod << " " << (ans.first*ans.second)%mod << " " << (ans.first*ans.second)%mod<<endl;
		ar.clear();
	}
	return 0;
}