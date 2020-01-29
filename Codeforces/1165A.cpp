#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
	int n,x,y;
	cin >> n >> x >> y;
	string s; cin >> s;
	int ans = 0;
	for(int i = n-1 ; i >= n-x; i--){
		if(s[i] == '1' && i!=n-y-1) ans++;
		else if( s[i] == '0' && i==n-y-1) ans++;
	}
	cout << ans << endl; 
	return 0;
}
