#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string> ss;
	string s;
	int n;
	while(cin>>n,n>0){
		cin >> s;
		n = s.size()/n;
		for(int i = 0 ; i < s.size() ; i+=n){
			ss.push_back(s.substr(i,n));
		}
		for(auto &v : ss) reverse(v.begin(),v.end());
		for(auto v : ss) cout << v;
		cout << endl;
		ss.clear();
	}
	return 0;
}
