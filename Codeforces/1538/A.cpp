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
    vector<int> a(n);
    for(int &i:a) cin >> i;
    int M = -1, Mi = 0, m = INT_MAX, mi = 0;
    for(int i = 0 ; i < n ; i++){
      if(M < a[i]) M = a[i], Mi = i;
      if(m > a[i]) m = a[i], mi = i;
    }
    int one = min(mi,Mi), two = max(mi,Mi);
    cout << min(two+1,min(n-one,one+1 + n-two)) << endl;
  }
	return 0;
}