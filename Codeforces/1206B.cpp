#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ii pair<int,int>
#define N 0
typedef long long ll;
 
using namespace std;
int n;
ll a[100005];
 
int main(){
	
	cin >> n;
	for(int i = 0 ; i< n ;i++) cin >> a[i];
	int cp = 0, cn = 0 , c0 = 0;
	for(int i = 0 ; i< n ;i++){
		if(a[i]==0) c0++;
		if(a[i]<0) cn++;
	}
	ll res = 0;
	for(int i = 0 ; i< n ;i++){
		if(a[i]>=0) res += abs(a[i]-1);
		else res += -a[i]-1;
	}
	if(cn%2==1 && c0==0) res += 2;
	cout << res << endl;
	return 0;
}
