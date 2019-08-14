#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
typedef long long ll;
using namespace std;
 
ll a,b;
ll res;
ll qp[20];
ll temp;
ll solve(string s){
	if(s=="0") return 0ll;
	ll ret = min(s[0],s[s.size()-1])-'0';
	int n = s.size();
	for(int i = 1 ;i < (n+1)/2 ; i++){
		ret *= 1ll*(min(s[i],s[s.size()-i-1])-'0'+1);
	}
	return ret;
}
int main(){
	int t;	cin >> t;
	int p = 0;
	qp[0] = 0ll;
	ll acum = 0;
	string i = "9";
	for(int j = 1; j <= 19; j++){
		acum += solve(i);
		qp[j] = acum;
		i += "9";	
	}
	while(t--){
		p++;
		cin >> a >> b;
		if(a>b){
			temp = a;
			a = b;
			b = temp;
		}
		a = max(a-1,0ll);
		//cout << a<< " " << b << endl;
		res = solve(to_string(b)) + qp[to_string(b).size()-1] - solve(to_string(a)) - qp[to_string(a).size()-1];
		cout << solve(to_string(b))<<" "<< qp[to_string(b).size()-1]<<" "<<solve(to_string(a))<<" "<<qp[to_string(a).size()-1]<<endl;
		printf("Case %d: %lld\n",p,res);
	}
	return 0;	
}
