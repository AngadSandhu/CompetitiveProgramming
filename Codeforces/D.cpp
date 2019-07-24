#include<bits/stdc++.h>
using namespace std;
int v[1000005];
bool prime(int n){
	for(int i = 2; i*i <= n ; i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n; cin >> n;
	if(prime(n)){
		cout << n << endl;
		for(int i =1 ; i < n ; i++){
			cout << i << " " << i+1 << endl;
		}
		cout << n << " " << 1 << endl;
	}else{
		int w = 0;
		for(int i = 1; i <= n/2 ; i++){
			if(prime(n+i)){
				w = i;
			 	break;
			 }
		}
		cout << n+w << endl;
		for(int i =1 ; i < n ; i++){
			cout << i << " " << i+1 << endl;
		}
		cout << n << " " << 1 << endl;
		for(int i = 1; i <= w ; i++){
			cout << i << " " << n/2 + i << endl;
		}
	}
}
