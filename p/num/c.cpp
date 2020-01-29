#include<bits/stdc++.h>
using namespace std;
#define N 10000005
int n;
bool noprime[N];
int p[N],cnt = 0;
int main(){
	noprime[1] = 1;
	for(int i = 2 ; i*i < N ; i++){
		if(noprime[i]) continue; 
		for(int j = i*i ; j < N ; j += i){
			noprime[j] = 1;
		}
	}
	for(int i = 2 ; i < N ; i++){
		if(!noprime[i]) p[cnt++] = i;
	}
	while(cin >> n){
		if(n<8) cout << "Impossible.\n";
		else{
			if(n%2) n-=5, cout << "2 3 ";
			else n-=4, cout << "2 2 ";
			for(int i = 0 ; i < cnt && p[i]<n ; i++){
				if(!noprime[n-p[i]]){
					cout << p[i] << " " << n-p[i] << endl;
					break;
				}
			}
		}
	}
	return 0;
}
