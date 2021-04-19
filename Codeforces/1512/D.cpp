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
    ll sum = 0;
    vector<int>a(n+2);
    for(int &i : a) cin >> i, sum += i;
    sort(a.begin(),a.end());
    sum -= a[n+1] + a[n];
    if(sum == a[n]){
      for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
      cout << endl;
    }else{
      int idx = -1;
      sum += a[n];
      for(int i = 0 ; i < n+1 ; i++){
        if(sum - a[i] == a.back()) idx = i;
      }
      if(idx == -1) cout << -1 << endl;
      else {
        for(int i = 0 ; i < n+1 ; i++){
          if(idx == i) continue;
          cout << a[i] << " ";
        }
        cout << endl;
      }
    }
  }
	return 0;
}