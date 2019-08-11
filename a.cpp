#include<bits/stdc++.h>
#define pb push_back     
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n;

int main(){
	int t;
	int p = 0;
	while(cin>>n,n>0){p++;
		int r = 3;
		ll res = 0;
		for(int l = 1 ; l <= n ; l++){
			while((n-r+1)>(r-l-1) && (r-l-1)>l) r++, res++;
		}
		printf("Case %d: %lld\n",p,res);
	}
	return 0;
}
