#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))

typedef long long ll;
using namespace std;

int a[1000005];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	int c = 0,mx = -1;
	for(int i = 0 ; i < n ; i++){
		c++;
		mx = max(mx,c);
		if(a[i]==a[i+1]) c = 0;
	}
	cout << mx << endl;
	return 0;
}
