#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;

string s;
int n;
int main(){
	cin >> n;
	bool p = 1;
	for(int i = 1,a ; i <= n  ; i++){
		cin >> s;
		if(s=="mumble") continue;
		if(stoi(s)!=i){ p = 0;}
	}
	cout << (p?"makes sense":"something is fishy") << endl;
	
	return 0;
}


