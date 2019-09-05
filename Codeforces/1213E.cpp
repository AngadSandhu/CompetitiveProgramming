#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	string abc = "abc";
	vector<string> check;
	do{
		string s = "";
		for(int i = 0 ; i < n ;i++) s += abc;
		check.push_back(s);
		check.push_back(string(n,abc[0])+string(n,abc[1])+string(n,abc[2]));
	}while(next_permutation(abc.begin(),abc.end()));
	cout << "YES" << endl;
	for(auto s : check){
		if(s.find(a)==string::npos && s.find(b)==string::npos){ cout << s << endl; return 0;}
	}
	return 0;
}
