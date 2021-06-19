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
    if(n%2) cout << "Bob" << endl;
    else{
      if(__builtin_popcount(n) != 1) cout << "Alice" << endl;
      else cout << ((31-__builtin_clz(n))%2 ? "Bob" : "Alice") << endl;
    }
  }
	return 0;
}