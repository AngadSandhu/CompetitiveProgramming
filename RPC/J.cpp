#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 100005
using namespace std;
typedef long long ll;
string s;

int n,t;
bool a[10],p;
int memo[N],ans1 = INT_MAX,ans2=INT_MAX;
int main(){
	cin >> n;
	for(int i = 0,x ; i < n ;i++){
		cin >> x;
		a[x] = 1;
	}
	cin >> t;
	for(int i = t ; i >=0 ;i--){
		s = to_string(i); p =1;
		for(int j = 0 ; j < s.size(); j++){
			if(a[s[j]-'0']==1) p = 0;
		}
		if(p){
			ans1 = t-i;
			break;
		}
	}
	for(int i = t ; i <= 999 ; i++){
		s = to_string(i); p = 1;
		for(int j = 0 ; j < s.size(); j++){
			if(a[s[j]-'0']==1) p = 0;
		}
		if(p){
			ans2 = i-t;
			break;
		}
	}
	cout << min(ans1,ans2) << endl;
	return 0;
}


