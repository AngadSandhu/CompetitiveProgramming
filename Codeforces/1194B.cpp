#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m;
int r[N], c[N];
vector<string> a;
int main(){
	int q; cin >> q;
	string s;
	while(q--){
		cin >> n >> m;
		a.clear();
		for(int i = 0 ; i < n ; i++){ cin >> s; a.push_back(s); }
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j++){
				if(a[i][j] == '.'){ r[i]++; c[j]++; }
			}
		}
		int mini = INT_MAX;	
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				mini = min(mini,r[i]+c[j]-((a[i][j]=='.')?1:0));
			}
		}
		cout << mini << endl;
		for(int i = 0 ; i < max(n,m) ; i++) r[i] = c[i] = 0;
	}
	return 0;
}
