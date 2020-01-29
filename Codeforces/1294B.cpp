#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin >> t;
	while(t--){
		int n;
		vector<pair<int,int>> v;
		cin >> n;
		v.push_back({0,0});
		for(int i = 0 ; i < n ; i++){
			int x,y; cin >> x >> y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		string res = "";
		bool pos = 1;
		for(int i = 1 ; i <= n ; i++){
			int b = v[i].first - v[i-1].first;
			if(b<0){ pos = 0; break; }
			for(int j = 0 ; j < b ; j++) res += 'R';
			int a = v[i].second - v[i-1].second;
			if(a<0){ pos = 0; break;}
			for(int j = 0 ; j < a ; j++) res += 'U';
		}
		if(pos==0) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			cout << res << endl;
		}
	}
	return 0;
}

