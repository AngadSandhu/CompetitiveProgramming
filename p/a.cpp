#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 10;
	vector<int> a(n), b(n);
	for(int i = 0 ; i < n ; i++) a[i] = 1;
	for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
	cout << endl;
	for(int i = 0 ; i < n ; i++){
		int res = 0;
		for(int j = 0 ; j < n ; j++){
			if(i==j) continue;
			res |= a[i]&a[j];
		}
		b[i] = res;
	}
	int cur = b[0], res = 0;
	for(int i = 0 ; i < n ; i++){
		cur &= b[i];
	}
	for(int i = 0 ; i < 29 ; i++) if((cur&(1<<i))==0) res += 1<<i;
	for(int i = 0 ; i < n ; i++) cout << b[i] << " ";
	cout << endl;
	cout << res << endl;
	return 0;
}