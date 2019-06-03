#include <bits/stdc++.h>
using namespace std;
map<string,int>m1;
map<int,string>m2;
vector<pair<int,int>> pairs;
vector<string> names;
int main() {
	int n,m,max=0,sol = 0;
	string name,name2;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> name;
		names.push_back(name);
	}
	sort(names.begin(),names.end());
	for(int i = 0 ; i < n; i ++){
		m1[names[i]] = i;
	}
	for(int i = 0 ; i < m ; i++){
		cin >> name >> name2;
		pairs.push_back(make_pair(m1[name],m1[name2]));
	}
	
	for(int i = 0 ; i < (1<<n) ; i++){
		bool pos = true;
		for(int j = 0 ; j < m ; j++){
			if( (i&(1<<pairs[j].first)) && (i&(1<<pairs[j].second)) ){
				pos = false;
				break;
			}
		}
		if(pos && __builtin_popcount(i) > max){
		max = __builtin_popcount(i);
		sol = i;
		}
	}
	if(m !=0) cout << max<< endl;
	else{
		cout << n << endl;
		for(int i = 0 ; i < n ; i++){
			cout << names[i] << endl;
		}
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(sol&(1<<i)) cout << names[i]<< endl;
	}
	return 0;
}
