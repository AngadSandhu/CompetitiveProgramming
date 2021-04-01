#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0 ; i < n ; i++)cin >> x[i] >> y[i];
    int xm = INT_MAX, ym = INT_MAX;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    xm = x[n/2] - x[n/2-1] + 1;
    ym = y[n/2] - y[n/2-1] + 1;
    if(n%2==1){
      cout << 1 << endl;
    }else{
      cout << 1ll*xm*ym << endl;
    }
  }
	return 0;
}