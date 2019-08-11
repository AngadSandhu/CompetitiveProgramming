#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[200005];
int main(){
	cin >> n >> k;
	for(int i =0 ; i < n ; i++) cin >> a[i];
	sort(a,a+n);
	long long l = 1, r = 20000000005,med;
	long long sum = 0;
	for(int j = 0 ; j < 70; j++){
		sum = 0;
		med = (l+r)/2;
		for(int i = n/2 ; i < n ;i++){
			sum+= max(med-a[i],0ll);
		}
		if(sum<=k) l = med;
		else r = med;
	}
	cout << l << endl;
	return 0;
}
