#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int t;
	getline(cin,s);
	t = stoi(s);
	int p = 0;
	while(t--){
		if(p!=0) cout << endl;
		p++;
		getline(cin,s);
		getline(cin,s);
		stringstream in(s);
		vector<pair<int,string> > a;
		int n;
		while(in>>n){
			a.push_back({n,""});
		}
		getline(cin,s);
		stringstream in2(s);
		for(int i = 0 ; i < a.size() ;i++){
			string f; in2 >> f;
			a[i].second = f;
		}
		sort(a.begin(),a.end());
		for(auto v : a) cout << v.second << endl;
	}
	return 0;
}
