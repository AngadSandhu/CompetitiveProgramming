#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		bool losesfirst = 0;
		int m,n,r,c;
		cin >> m >> n >> r >> c;
		int p[4] = {c,r,m-r-1,n-c-1};
		if(p[0]<=1 && p[1]<=1 && p[2]<=1 && p[3]<=1){
			if((p[0]+p[1]+p[2]+p[3])%2) losesfirst = 1;
		}else{
			if( (p[0]^p[1]^p[2]^p[3]) == 0) losesfirst = 1;
		}
		if(losesfirst) cout << "Hansel" << endl;
		else cout << "Gretel" << endl;
	}
	return 0;
}
