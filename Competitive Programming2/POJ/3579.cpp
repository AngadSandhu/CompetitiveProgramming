#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,num[100000],c;

bool f(int m){
	c = 0;
	if(m > num[n-1]) return true;
	for(int j = 0 ; j < n-1 ; j++){
		c += (upper_bound(num,num+n,m+num[j])- num) - (j+1);
	}
	return 4*c >= n*(n-1);
}

int main() {
	while(scanf("%d",&n) == 1){
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int l = 0, r = 1e9,m;
		for(int i = 0 ; i < 31 ; i++){
			m = (l+r)/2;
			if(f(m)) r = m;
			else l = m+1;
		}
		printf("%d\n",m);
	}
	return 0;
}
