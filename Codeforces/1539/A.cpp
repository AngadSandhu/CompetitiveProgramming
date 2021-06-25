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
    ll n,x,t; cin >> n >> x >> t;
    ll c = t/x;
    cout << max(0ll,n-c)*c + min(n-1,c-1)*min(n,c)/2 << endl;
  }
	return 0;
}