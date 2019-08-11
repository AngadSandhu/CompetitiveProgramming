#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 100005
using namespace std;
typedef long long ll;
string s;

int n;
int a[N];
int dp[N];
int nex[N];

int main(){
	cin >> n;
	for(int i = 1; i <=n ;i++){
		cin >> a[i];
		nex[a[i]] = i;
	}
	a[0] = 0;
	for(int i = 1 ;i <= n ; i++) dp[i] = 1;
	for(int i = n ; i>0 ; i--){
		if(nex[a[i]+1] == 0 || nex[a[i]+1]<i) continue;
		dp[i] = dp[nex[a[i]+1]] + 1;
	}
	int maxi = -1;
	for(int i = 1 ; i <= n ; i++) maxi = max(maxi,dp[i]);
	cout << n-maxi << endl;
	return 0;
}


