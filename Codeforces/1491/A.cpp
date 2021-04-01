#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
  int n,q; cin >> n >> q;
  vector<int> a(n);
  int ones = 0;
  for(int &i: a) cin >> i, ones += i;
  while(q--){
    int t,k; cin >> t >> k;
    if(t==1){
      a[k-1] = !a[k-1];
      if(a[k-1]) ones++;
      else ones--;
    }else{
      if(k > ones) cout << 0 << endl;
      else cout << 1 << endl;
    }
  }

	return 0;
}