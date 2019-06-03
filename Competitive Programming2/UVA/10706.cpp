#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 33000
int main() {
	ll a =0,t=0,g[N],T,p;
	string s = "";
	cin >> T;
	for(int i = 1 ; i < N ; i++){
		a += (int)log10(i)+1;
		t += a;
		g[i] = t;
		s += to_string(i);
	}
	while(T--){
		cin >> p;
		int l = 0, r = N,m;
		while(l < r){
			m = (l+r)/2;
			if(g[m] < p){
				if(m == l) break;
			l = m;
			}
			else r = m;
		}
		cout << s[p-g[m]-1] << endl;
	}
	return 0;
}
