#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

bool comp(int a,int b){
  return abs(a) < abs(b);
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<ll> x, y;
    for(int i = 0 ; i < 2*n ; i ++){
      ll a,b; cin >> a >> b;
      if(a==0) y.pb(b);
      if(b==0) x.pb(a);
    }
    sort(x.begin(),x.end(),comp);
    sort(y.begin(),y.end(),comp);
    double ans = 0;
    for(int i = 0 ; i < n ; i++){
      ans += sqrt(x[i]*x[i] + y[i]*y[i]);
    }
    printf("%.9lf\n",ans);
  }
	return 0;
}