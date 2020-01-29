#include <bits/stdc++.h>
using namespace std;
vector<string> v;

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s;
		int cp= 0,ci= 0;
		int res = 0,nres= 0;
		for(int i = 0 ; i < n ; i++){
			cin >> s;
			for(int j = 0 ; j < s.size() ; j++){
				if(s[j]=='0') cp++;
				else ci++;
			}
			if(s.size()%2==0 && ci%2==0 && cp%2==0) res++;
			else if(s.size()%2==0 && ((ci%2==0 &&cp%2==1) || (ci%2==1 && cp%2==0))) nres++;
			if(s.size()%2==1 && ((ci%2==0 &&cp%2==1) || (ci%2==1 && cp%2==0))) res++;
			else if(s.size()%2==1 && ci%2==1 && cp%2==1) nres++;
		}
		cout << res + nres/2 << endl;
	}
	return 0;
}
