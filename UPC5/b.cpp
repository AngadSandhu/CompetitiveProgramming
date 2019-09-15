#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;cin >> n;
	int a[n];
	ll res = 0;
	for(int &i:a) cin >> i;
	sort(a,a+n);
	ll gc = 0;
	for(int i = 0 ; i < n ;i++){
		gc = __gcd(gc,1ll*a[i]);
	}
	res = a[n-1]/gc - n;
	cout << (res%2?"Alice":"Bob") << endl;
	return 0;
}
