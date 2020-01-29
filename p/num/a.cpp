	#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n;
bool noprime[N];
int p[N],cnt = 0;
int main(){
	for(int i = 2 ; i*i < N ; i++){
		if(noprime[i]) continue; 
		for(int j = i*i ; j < N ; j += i){
			noprime[j] = 1;
		}
	}
	for(int i = 2 ; i < N ; i++){
		if(!noprime[i]) p[cnt++] = i;
	}
	while(cin >> n, n > 0){
		for(int i = 2 ; i < n ; i++){
			if(!noprime[i] && !noprime[n-i]){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
