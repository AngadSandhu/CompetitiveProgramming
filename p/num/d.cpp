#include<bits/stdc++.h>
using namespace std;
#define N 20000005
int k;
bool noprime[N];
int p[N],cnt = 0;
int main(){
	for(int i = 2 ; i*i < N ; i++){
		if(noprime[i]) continue; 
		for(int j = i*i ; j < N ; j += i){
			noprime[j] = 1;
		}
	}
	for(int i = 2 ; i < N-2 ; i++){
		if(!noprime[i] && !noprime[i+2]){
			p[cnt++] = i;
		}
	}
	while(cin >> k){
		printf("(%d, %d)\n",p[k-1],p[k-1]+2);
	}
	return 0;
}
