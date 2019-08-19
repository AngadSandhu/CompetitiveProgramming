#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ii pair<int,int>
#define N 0
typedef long long ll;
 
using namespace std;
int n;
int a[40000005];
 
int main(){
	cin >> n;
	n *= 2;
	for(int i = 1 ; i <= 2*n ; i++) a[i]= i;
	ll s = n*(n+1)/2, d = s/2, u = (ll)ceil((1.0*s)/2);
	int c = 1;
	for(int i = 1 ; i <= n/2 ;i++){
		if(i%2==0){
			a[i] = c+1;
			a[n/2+i] = c;
		}else{
			a[i] = c;
			a[i+n/2] = c+1;
		}
		c+=2;
	}
	bool b = 1;
	ll sum = 0;
	//for(int i = 1 ; i <= n ;i++)cout << a[i] << " ";
	/*
	for(int i = 1 ; i <= n/2;i++){
		sum += a[i];
	}
	for(int i = 1 ; i <= n && b ;i++){
		if(sum!=d&&sum!=u) b = 0;
		sum -= a[i];
		sum += a[(i+n/2>n)?(i+n/2-n):(i+n/2)];
	}*/
	if((n/2)%2){
		cout << "YES\n";
		for(int i = 1 ; i <= n ;i++) cout << a[i] << " ";
		cout << endl;
	}else{
		cout << "NO\n";
	}
	return 0;
}
