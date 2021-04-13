#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int lis(vector<int> &v){
  vector<int> d;
  for(int i = 0 ; i < v.size() ; i++){
    int j = lower_bound(d.begin(),d.end(),v[i]) - d.begin();
    if(j == d.size()) d.pb(v[i]);
    else d[j] = v[i];
  }
  return d.size();
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    reverse(a.begin(),a.end());
    for(int i = n-1 ;  i >= 0 ; i--) a.pb(a[i]);
    cout << lis(a) << endl;
  }
	return 0;
}