#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >>t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n+2);
    for(int i = 1 ; i <= n; i ++) cin >> a[i];
    a[n+1] = 0;
    ll rest = 0, sum = 0;
    for(int i = 1 ; i <= n+1; i ++){
      sum += abs(a[i]-a[i-1]); 
    }
    for(int i = 1 ; i <= n; i ++){
      if(max(a[i-1],a[i+1]) < a[i]){
        rest += a[i]-max(a[i-1],a[i+1]);
        a[i] = max(a[i-1],a[i+1]);
      }
    }
    // cout << rest << endl;
    cout << sum - rest << endl;
  }
	return 0;
}