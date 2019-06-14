#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	while(cin >> n >> m, n > 0){
		vector<int> cant;
		while(n>0&&m>0){
			if(n>m){
				cant.push_back(n/m);
				n = n%m;
			}else{
				cant.push_back(m/n);
				m = m%n;
			}
		}
		int c = 0;
		for(auto i : cant){
			if(i!=1) break;
			c++;
		}
		if(c%2==1 && cant.size()>1) cout << "Ollie wins\n";
		else cout<< "Stan wins\n";
	}
	return 0;
}
