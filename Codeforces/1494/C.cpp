#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 300005
int n,m;
int cnt(vector<int> &a,int l,int r){
  return upper_bound(a.begin(),a.end(),r) - lower_bound(a.begin(),a.end(),l);
}
int solve(vector<int> a, vector<int> b){
  if(b.size()==0) return 0;
  vector<int> bet(b.size()),cont(b.size());
  map<int,int> mp;
  for(int i = 0 ; i < (int)b.size(); i++) mp[b[i]] = 1;
  vector<int> bef(a.size()+1);
  bef[0] = 0;
  for(int i = 1 ; i < (int)bef.size() ; i++){
    bef[i] = bef[i-1];
    bef[i] += mp[a[i-1]];
  }
    int l = 0, carry = 0;
    for(int r = 0 ; r < (int)b.size() ; r++){
      while(l < (int)a.size() && a[l] <= b[r]){
      carry++;
        l++;
      }
      bet[r] = carry;
    }
    int curr = 1;
    cont[(int)cont.size()-1] = curr;
    
    for(int i = (int)b.size()-2 ; i >= 0 ; i--){
      if(b[i] == b[i+1]-1) curr++;
      else curr = 1;
      cont[i] = curr;
    }
    int maxi =0;
    //cout << "m: " << maxi << endl;
    for(int i = 0 ; i < (int)b.size() ; i++){
      maxi = max(maxi,cnt(b,b[i],b[i]+bet[i]-1)-bef[bet[i]]);
      cout <<maxi << " " << bet[i] << " " << cnt(b,b[i],b[i]+bet[i]-1) << " " << bef[bet[i]] << endl;
    }
    cout << "ans: "<< maxi+ bef[a.size()] << endl;
    return maxi+ bef[a.size()];
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n >> m;
    vector<int> a,a2,b,b2;
    ll ans = 0;
    for(int i = 0 ; i < n ; i ++){
      int x; cin >> x;
      if(x > 0) a.pb(x);
      else a2.pb(-x);
    }
    for(int i = 0 ; i < m ; i ++){
      int x; cin >> x;
      if(x > 0) b.pb(x);
      else b2.pb(-x);
    }
    ans += solve(a,b);
    reverse(a2.begin(),a2.end());
    reverse(b2.begin(),b2.end());
    ans += solve(a2,b2);
    cout << ans << endl;
  }
	return 0;
}