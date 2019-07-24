#include<bits/stdc++.h>
using namespace std;
long long res = 0;
int main(){
	string s;
	cin >> s;
	long long tot = 0;
	for(int i = 0 ; i < s.size()-1; i++){
		if(s[i] == 'v' && s[i+1] == 'v') tot++;
	}
	int c = 0;
	for(int i = 0 ; i < s.size(); i++){
		if(s[i] == 'v' && s[i+1] == 'v') c++;
		if(s[i] == 'o') res += c*(tot-c);
	}
	cout << res << endl;
	return 0;
}
