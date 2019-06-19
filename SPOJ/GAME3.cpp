#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		long long n; cin >> n;
		bool win=0;
		long long c = 0;
		if(n%2==0) win = 0;
		else if(n==3) win = 1;
		else{
		long long m = n;
			while(m>1){
				m = m/2;
				c++;
			}
			if(c%2==0) win = 0;
			else{
			if((n>>(c-1))%2==0) win = 1;
				else win = 0;
			}
		}
		string r =  win ? "Ivica" : "Marica";
		cout << r << endl;
	}
	return 0;
}
