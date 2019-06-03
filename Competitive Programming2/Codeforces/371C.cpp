#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000000001000
	string hamb;
	int nb,ns,nc,pb,ps,pc,rb = 0,rs = 0,rc = 0;
	ll dhave;
	
bool canmake(ll cant);

int main() {

	cin >> hamb >> nb >> ns >> nc >> pb >> ps >> pc >> dhave;
	for(int i = 0 ; i < hamb.length() ; i++){
		if(hamb[i] == 'B') rb++;
		if(hamb[i] == 'S') rs++;
		if(hamb[i] == 'C') rc++;
	}
	ll l = 0,r = N ,med;
	while(l < r){
		med = (l + r)/2;
		if(canmake(med)){
			if(med == l){
				break;
			}
			 l = med;
		}
		else r = med;
	}
	cout << l;
	return 0;
}
bool canmake(ll cant){
	ll dneed = 0;
	dneed += max((cant*rb-nb)*pb,(ll)0);
	dneed += max((cant*rs-ns)*ps,(ll)0);
	dneed += max((cant*rc-nc)*pc,(ll)0);
	return dneed <= dhave;
}
