#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll a[3];
int w[7] = {0,1,2,0,2,1,0};
int main(){
	cin >> a[0]>>a[1]>>a[2];
	ll m = min(a[0]/3,min(a[1]/2,a[2]/2));
	a[0] -= m*3;
	a[1] -= m*2;
	a[2] -= m*2;
	ll mx = -1;
	for(int i = 0 ; i < 7 ; i++){
		ll c = 0, b[3] = {a[0],a[1],a[2]};	
		for(int j = 0 ; j < 7 ; j++){
			if(b[w[(i+j)%7]]==0){ mx = max(mx,c); break; }
			c++;
			b[w[(i+j)%7]]--;
		}
	}
	cout << m*7+mx << endl;
	return 0;
}
