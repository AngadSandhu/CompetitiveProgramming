#include <bits/stdc++.h>
using namespace std;
int f(int n){
	int c = 0;
	while(n>0){
		c+=n%10;
		n/=10;
	}
	return c;
}
int main() {
	int maxi = -1;
	for(int i = 99999999 ;i <= INT_MAX ; i++){
		maxi = max(maxi,f(i));
	}
	cout << maxi << endl;
	return 0;
}
