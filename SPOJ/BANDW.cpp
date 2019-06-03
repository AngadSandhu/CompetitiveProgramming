#include <bits/stdc++.h>
using namespace std;

int main() {
	int p[505];
	string a, b;
	while(cin >> a){
		if(a == "*")break;
		cin >> b;
		int n = a.length();
		for(int i = 0 ; i < n ; i++){
			if(a[i] == b[i]) p[i] = 0;
			else p[i] = 1;
		}
		bool flag = false;
		int cont = 0;
		for(int i = 0 ; i < n ; i++){
			if(p[i] == 1){
				if(!flag){
				flag = true;
				cont++;	
				} 
			}else{
				if(flag) flag = false;
			}
		}
		cout << cont << endl;
	}
	
	return 0;
}
