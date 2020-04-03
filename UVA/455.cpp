#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 
int minperiod(string s){
	int n = s.size();
	vector<int> b(n+1);
	b[0] = -1;
	for(int i = 0, j = -1 ; i <n ; i++){
		while(j!=-1 && s[i] != s[j]) j = b[j];
		b[i+1] = ++j;
	}
	if(n%(n-b[n]) == 0) return n-b[n];
	else return n;
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << minperiod(s) << endl;
		if(t) cout << endl;
	}
	return 0;
}
