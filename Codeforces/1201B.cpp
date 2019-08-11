#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main(){
	cin >> n;
	for(int i= 0 ; i < n ;i++) cin >> a[i];
	sort(a,a+n);
	long long sum = a[0];
	bool pos = 1;
	for(int i = 1 ; i < n ; i++){
		if(a[i]>sum){pos = 0;}
		sum += a[i];
	}
	if(pos && sum%2==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
