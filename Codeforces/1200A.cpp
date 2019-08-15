#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
typedef long long ll;
using namespace std;
 
string s;
ll n,m;
bool p = 1;
ll sx,sy,ex,ey;
ll a,b;
int main(){
int t;
	cin >> n >> m >> t;
	while(t--){
		p = 1;
		cin >>sx>>sy>>ex>>ey;
		ll temp;
		a = n/__gcd(n,m);
		b = m/__gcd(n,m);
		if(__gcd(n,m)==1) p = 1;
		else if((sy-1)/((sx==1)?a:b) == (ey-1)/((ex==1)?a:b)) p = 1;
		else p = 0;
		cout << (p?"YES":"NO")<<endl;
	}
	return 0;	
}

