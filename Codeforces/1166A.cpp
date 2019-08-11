#include<bits/stdc++.h>
using namespace std;
string a[105];
int f[30];
int main(){
	int n;
	cin >> n;
	for(int i = 0 ;i < n ;i++) cin >> a[i];
	for(int i = 0 ;i < n ;i++) f[a[i][0]-'a']++;
	int res = 0;
	for(int i = 0 ;i < 30 ;i++){
		int a = f[i]/2,b= f[i]-a;
		res+= (a*(a-1))/2 + (b*(b-1))/2;
	}
	cout << res << endl;
	
}
