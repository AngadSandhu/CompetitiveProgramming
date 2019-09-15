#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
bool solved[3][10005];
int main(){
	int t,p = 0;cin >> t;
	while(t--){
		p++;
		memset(solved,0,sizeof solved);
		for(int i = 0 ; i < 3 ; i++){
			int m; cin >> m;
			for(int j  =0 ; j < m ; j++){
				int a; cin >> a; solved[i][a] = 1;
			}
		}
		vector<int>sol[3];
		for(int i = 0 ; i < 3 ; i++){
			for( int j  =0 ; j < 10005 ; j++){
				if(solved[i][j] && !solved[(i+1)%3][j] && !solved[(i+2)%3][j]) sol[i].push_back(j);
			}
		}
		int mx = -1;
		for(int i = 0 ;i < 3 ;i++){
			mx = max(mx,(int)sol[i].size());
			sort(sol[i].begin(),sol[i].end());
		}
		printf("Case #%d:\n",p);
		for(int i = 0 ; i < 3 ; i++){
			if(mx!=sol[i].size()) continue;
			cout << i+1 << " " <<sol[i].size();
			if(sol[i].size()>0)cout << " ";
			for(auto v : sol[i]){
				cout << v;
				if(v!=sol[i].back()) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
