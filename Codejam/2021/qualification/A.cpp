#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  int caso = 1;
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    ll ans = 0;
    for(int i = 0 ; i < n-1; i++){
      int mini = INT_MAX, miniId = i;
      for(int j = i ; j < n ; j++){
        if(mini > a[j]){
          mini = a[j];
          miniId = j;
        }
      }
      ans += miniId-i+1;
      reverse(a.begin()+i,a.begin()+miniId+1);
    }
    cout << "Case #" << caso++ << ": " << ans << endl;
  }
	return 0;
}