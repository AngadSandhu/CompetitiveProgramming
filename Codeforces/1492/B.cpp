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
    vector<int> p(n);
    for(int &i : p) cin >> i;
    vector<int> ans, curr,maxs(n);
    int maxi = 0;

    for(int i = 0 ; i < n ; i++){
      maxi = max(maxi,p[i]);
      maxs[i] = maxi;
    }
    maxi = n;
    for(int i = n-1 ; i >=0 ; i--){
      curr.pb(p[i]);
      if(maxi == p[i]){
        reverse(curr.begin(),curr.end());
        for(int j : curr) ans.pb(j);
        curr.clear();
        if(i>0) maxi = maxs[i-1];
      }
    }
    reverse(curr.begin(),curr.end());
    for(int j : curr) ans.pb(j);
    for(int i : ans) cout << i << " ";
    cout << endl;

  }
	return 0;
}