#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m,k;
ll a[100005];
int main(){
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++) scanf("%lld",&a[i]);
	ll i2 = 0,i1 = 0, nk = k,cnt = 0;
	while(i2<m){
		i2 = upper_bound(a,a+m,nk)-a;
		if(i2==i1){ nk += (i2+1-nk)/k+k; }
		else nk+= i2 - i1;
		i1=i2;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
