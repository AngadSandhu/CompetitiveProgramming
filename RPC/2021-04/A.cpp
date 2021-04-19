#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
  vector<int> a(n);
  for(int & i: a) cin >> i;
  sort(a.begin(),a.end());
  a.pb(INT_MAX);
  ll ans = 0;
  for(int i = 0 ; i < n ;i++){
    ans += a[i];
    while(i < n && a[i] + 1 == a[i+1]) i++;
  }
  cout << ans << endl;
	return 0;
}