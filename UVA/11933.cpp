#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	while(cin >> n,n>0){
		ll a = 0 ,b = 0,c = 0;
		bool p;
		for(int i = 0 ; i < 32 ; i++){
			p = 0;
			if(n&(1<<i)) c++, p = 1;
			 if(p) if(c%2==0){
				b |= (1<<i);
			}else{
				a |= (1<<i);
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}
