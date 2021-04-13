#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
vector<int> lis(vector<int> &v){
  vector<int> d;
  vector<int> ret(v.size());
  for(int i = 0 ; i < v.size() ; i++){
    int j = lower_bound(d.begin(),d.end(),v[i]) - d.begin();
    if(j == d.size()) d.pb(v[i]);
    else d[j] = v[i];
    ret[i] = d.size();
  }
  return ret;
}
int main(){
	FIO;
	int n;
  while(cin >> n){
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> lisPos = lis(a);
    reverse(a.begin(),a.end());
    vector<int> ldsPos = lis(a);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      int j = n-1-i;
      if(lisPos[i] == ldsPos[j]) ans = max(ans,lisPos[i] + ldsPos[j] - 1);
    }
    cout << ans << endl;
  }
	return 0;
}