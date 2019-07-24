#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n , m; cin >> n >> m;
	long long a, b;
	for(long long i = 0 ; i< 100005; i ++){
		if((i*(i+3))/2 == (m+n)){
			a = i;
			break;
		} 
	}
	cout << n - a << endl;

}
