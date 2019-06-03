#include <bits/stdc++.h>
using namespace std;
int n,m,k,seq[1000005];

bool f(int len){
	int r = len ,freq[1005] = {},cont = 0;
	for(int l = 0 ; l <= r -1 ; l++){
		if(freq[seq[l]] == 0 && seq[l] <= k){
		freq[seq[l]]++;
		cont++;
		}else if(freq[seq[l]] >= 1) freq[seq[l]]++;
	}
	for(int l = 1 ; l <= n-len; l++, r++){
		if(cont == k) return true;
		if(freq[seq[r]] == 0 && seq[r] <= k){
		freq[seq[r]]++;
		cont++;
		}else if(freq[seq[r]] >= 1) freq[seq[r]]++;
		
		if(freq[seq[l-1]] == 1){
			freq[seq[l-1]]--;
			cont--;
		}else if(freq[seq[l-1]] > 1) freq[seq[l-1]]--;
		
	}
	
	return cont == k;
}

int main() {
	int t, p = 0; cin >> t;
	while(t--){
		p++;
		cin >> n >> m >> k;
		for(int i = 0 ; i < n ; i ++){
			if(i == 0) seq[i] = 1;
			if(i == 1) seq[i] = 2;
			if(i == 2) seq[i] = 3;
			if(i > 2) seq[i] = (seq[i-1] + seq[i-2] + seq[i-3])%m +1;
		}
		int l = 0, r = n, med;
		while(l < r){
			med = l + (r-l)/2;
			if(f(med)) r = med;
			else l = med+1;
		}
		if(!f(l)){
			printf("Case %d: sequence nai\n",p);
			continue;
		}
		printf("Case %d: %d\n",p,l);
	}
	return 0;
}
