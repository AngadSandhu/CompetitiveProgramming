#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int & i : a) cin >> i;
	int res = 0;
	bool b = 1;
	for(int i = 1 ; i < n && b; i++){
		if((a[i]==3 && a[i-1]==1)||(a[i]==1 && a[i-1]==3)) res+=4;
		
		if(a[i]==2 && a[i-1]==1 && i>1 && a[i-2]==3) res+=2;
		else if(a[i]==2 && a[i-1]==1) res += 3;
		if(a[i]==1 && a[i-1]==2) res += 3;
		if((a[i]==3 && a[i-1]==2)||(a[i]==2 && a[i-1]==3)) b = 0;
	}
	if(b) cout << "Finite\n" << res << endl;
	else cout << "Infinite\n";
	return 0;
}
