#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5];
int main(){
	int t; cin >> t;
	while(t--){
		int n;
		cin >> a[0] >> a[1] >> a[2] >> n;
		sort(a,a+3);
		n -= 2*a[2] - a[1]- a[0];
		if(n >=0 && n%3==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
