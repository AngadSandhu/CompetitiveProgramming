#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;

string s;

long long  a,b,c;

int main(){
	cin >> a >> b >> c;
	cout << max(a-2*c,0ll)*max(b-2*c,0ll) << endl;
	return 0;
}


