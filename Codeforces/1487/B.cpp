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
    ll n,k; cin >> n >> k;
    if(n%2==0){
      k--;
      cout << k%n + 1 << endl;
    }else{
      ll x = n/2;
      k--;
      k += k/x;
      cout << k%n + 1 << endl;
    }
  }
	return 0;
}