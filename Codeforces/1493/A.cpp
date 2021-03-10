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
    int n,k; cin >> n >> k;
    vector<int> ans;
    for(int i = (k+1)/2; i <= k-1; i++){
      ans.pb(i);
    }
    for(int i = k+1 ; i <= n; i++){
      ans.pb(i);
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
    ans.clear();
  }
	return 0;
}