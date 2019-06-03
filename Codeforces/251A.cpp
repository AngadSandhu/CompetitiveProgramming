#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d,p[100005];
	cin >> n >> d;
	for(int i = 0; i < n ; i++){
		scanf("%d",&p[i]);
	}
	long long c = 0;	
	for(int i = 0; i < n ; i++){
		int j = upper_bound(p+i,p+n,p[i]+d)-p-1;
		if(j-i<2) continue;
		long long aux = max(j - i - 1,0);
		c += aux*(aux+1)/2;
	}
	cout << c << endl;
	return 0;
}
