#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
typedef long long ll;
using namespace std;
 
string s;
int n;
int a,b;

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		a = 2;
		for(int i = 2 ; i <= n ;i ++){
			if(((i)*(i-1))/2 > n) break;
			a=i;
		}
		cout << 133;
		for(int i = 0 ; i < n-(a*(a-1))/2; i++) cout << 7;
		for(int i = 0 ; i < a-2; i++) cout << 3;
		cout << 7 <<endl;
	}
	return 0;	
}
