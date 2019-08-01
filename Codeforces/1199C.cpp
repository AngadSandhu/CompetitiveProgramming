#include<bits/stdc++.h>
using namespace std;
int n,I;
int a[400005];
int main(){
	cin >> n >> I;
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int K = 1;
	for(int i = 1 ; i < n ; i++){
		if(a[i]!=a[i-1]) K++;
	}
	int k = (int)log2(K)+((int)log2(K)!=log2(K)?1:0), c = 0,l = 0, r = n-1,c1,c2,ll=0,rr=n-1;
	while((n*k)>(8*I)){
		c1 = c2 = 0;
		for(int i = l ; i < r ; i++){
			c1++; ll++;
			if(a[i]!=a[i+1]) break;
		}
		for(int i = r ; i > l; i--){
			c2++; rr--;
			if(a[i]!=a[i-1]) break;
		}
		if(c1<c2){
			l = ll;
			rr = r;
			c+=c1;
		}else{
			r =rr;
			ll = l;
			c+=c2;
		}
		K--;
		k = (int)log2(K)+((int)log2(K)!=log2(K)?1:0);
	}
	cout << c << endl;
	return 0;
}
