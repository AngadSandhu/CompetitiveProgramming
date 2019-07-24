#include<bits/stdc++.h>
using namespace std;
long long res = 1;
const long long mod = 998244353;
int w,h;
int main(){
	cin >> w >> h;
	for(int i = 0 ; i< w+h ; i++){
		res = 2*res%mod;
	}
	cout << res << endl;
	return 0;
}
