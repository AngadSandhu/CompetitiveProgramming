#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	while(cin >> n, n>0){
		int a[n];
		for(int &i:a) cin >> i;
		int r = 0;
		for(int i = 0 ; i < n ; i++){
			if((a[(i-1+n)%n]<a[i] && a[i]>a[(i+1)%n]) ||
				(a[(i-1+n)%n]>a[i] && a[i]<a[(i+1)%n])) r++;
		}
		cout << r << endl;
	}
	return 0;
}
