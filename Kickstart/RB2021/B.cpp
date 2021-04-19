#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
  int t; cin >> t;
	for(int nt = 1 ; nt <= t ; nt++){
    cout << "Case #" << nt << ": ";
    int n; cin >> n;
    vector<int> a(n),b;
    for(int &i: a) cin >> i;

    for(int i = 1 ; i < n ; i++) b.pb(a[i]-a[i-1]);
    vector<int> left(n),right(n);
    left[0] = 1;
    for(int i = 1 ; i < b.size() ; i++){
      if(b[i] == b[i-1]) left[i] = left[i-1] + 1;
      else left[i] = 1;
    }
    right[b.size()-1] = 1;
    for(int i = b.size()-2 ; i >= 0 ; i--){
      if(b[i] == b[i+1]) right[i] = right[i+1] + 1;
      else right[i] = 1;
    }
    int ans = 2;
    if(b.size() >= 4){
      for(int i = 1 ; i <= b.size()-3 ; i++){
        if((b[i] + b[i+1])/2 == b[i-1] && b[i-1] == b[i+2])
          ans = max(ans, 2 + left[i-1] + right[i+2]);
      }
    }
    for(int i = 1 ; i < b.size()-1 ; i++){
      ans = max(ans,1 + max(left[i],right[i]));
    }
    cout << ans+1 << endl;
  }
	return 0;
}