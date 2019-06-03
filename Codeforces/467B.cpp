#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k,army[10001],count = 0, aux,dif_bits=0;
	cin >> n >> m >> k;
	for(int i = 0; i < m+1; i++){
		cin >> army[i];
	}
	
	for(int i = 0; i < m; i++){
		aux = army[i]^army[m];
		dif_bits = 0;
		for(int j = 0; j < n ; j++){
			if((aux>>j)&1){
				dif_bits++;
			}
		}
		if(dif_bits <= k){
			count++;
		}
	}
	cout << count <<endl;
	return 0;
}
