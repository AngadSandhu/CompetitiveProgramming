#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
typedef long long ll;
 
using namespace std;
int main(){
	int n; cin >> n;
	int a[n];
	int c1 = 0 , c2 = 0;
	for(int i =0 ; i < n ; i++){
		cin >> a[i];
		if(a[i]%2) c1++;
		else c2++;
	}
	int res;
	if(c1>c2){
		res = c2;
	}
	else{
		res = c1;
	}
	cout << res << endl;
	return 0;
}

