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
bool a[400];
int memo[N];

int main(){
	cin >> n;
	for(int i = 0,x ; i < n ;i++){
		cin >> x;
		a[x] = 1;
	}
	ll sum = 0;
	int cnt = 0,c = 0;
	for(int i = 1 ; i <=365 ;i++){
		if(a[i]==1) c++;
		if(sum+c>=20){
			cnt++;
			c = 0;
			sum = 0;
			//cout << i << endl;
		}
		sum+=c;
	}
	if(sum>0) cnt++;
	cout << cnt << endl;
	return 0;
}


