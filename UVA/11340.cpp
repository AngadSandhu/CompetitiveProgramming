#include<bits/stdc++.h>
using namespace std;
int cost[1000];
int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		char a; int c;
		memset(cost,0,sizeof cost);
		while(k--){
			cin >> a >> c;
			cost[a+256] = c;
		}
		int n;
		cin >> n;
		string s;
		getline(cin,s);
		int res = 0;
		while(n--){
			getline(cin,s);
			for(auto v : s){
				res += cost[int(v)+256];
			}
		}
		printf("%d.%.2d$\n",(res-res%100)/100,res%100);
	}
	return 0;
}
