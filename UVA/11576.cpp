#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define reverse(ww) reverse(ww.begin(),ww.end())

int borde(string s){
	int n = s.size();
	vector<int> b(n+1);
	b[0] = -1;
	for(int i = 0, j = -1 ; i < n ; i++){
		while(j != -1 && s[i] != s[j]) j = b[j];
		b[i+1] = ++j;
	}
	return b[n];
}
int main(){
	int t; cin >> t;
	while(t--){
		int m,k;
		cin >> m >> k;
		vector<string> v(k);
		for(int i = 0 ; i < k ; i++){
			cin >> v[i];
		}
		int ans = m;
		for(int i = 0 ; i < k-1 ; i++){
			ans += m - borde(v[i+1] + "#" + v[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
