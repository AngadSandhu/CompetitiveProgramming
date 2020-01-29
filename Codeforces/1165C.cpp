#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
string res;
int main(){
	cin >> n >> s;
	for(int i = 0 ; i < n ; i++){
		if(res.size()%2==0 || res.back() != s[i]){
			res.push_back(s[i]);
		}
	}
	if(res.size()%2) res.pop_back();
	cout << n- res.size() << endl;
	cout << res << endl;
	return 0;
}

