#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int a[100005];
int main(){
	cin >> n >> x >> y;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	bool rainy = 1;
	int res = 0;
	for(int i = 0 ; i < n; i ++){
		rainy = 1;
		for(int j = 1 ; j <= x && i-j>=0; j++){
			if(a[i]>=a[i-j]) rainy = 0;
		}
		for(int j = 1 ; j <= y && i+j<n; j++){
			if(a[i]>=a[i+j]) rainy = 0;
		}
		if(rainy){ res = i; break; }
	}
	cout << res+1 << endl;
	return 0;
}
