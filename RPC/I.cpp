#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;

string s;
int n;
int f[30];
bool p;
int main(){
	cin >> s;
	n = s.size();
	int c1=0,c2=0;
	for(int i = 0  ; i < n  ;i++){
		f[s[i]-'a']++;
	}
	for(int i = 0  ; i < n  ;i++){
		if(f[s[i]-'a']%2)c2++;
		else c1++;
	}
	if(c1==n) cout << 0 << endl;
	else if(c2==n) cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}

