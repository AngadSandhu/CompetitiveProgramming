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
    int cnt = 0, m = INT_MAX;
    bool zero = 0;
    vector<int> a(n);
    for(int &i : a){
      cin >> i;
      if(i > 0) m = min(m,i);
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      if(a[i] <= 0){
        ans++;
      }
    }
    bool ok = 1;
    for(int i = 1 ; i < n ; i++){
      if(abs(a[i] - a[i-1]) < m && a[i] <= 0){
        ok = 0;
      }
    }
    if(ok && m != INT_MAX) ans++;
    cout << ans << endl;
  }
	return 0;
}