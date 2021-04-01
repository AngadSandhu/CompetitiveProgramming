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
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 1; i <= n ; i++){
      int x; cin >> x;
      if(x!=0) {
        v.pb({max(i-x+1,1),i});
      }
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>> pans;
    int l = 0, r = 0;
    for(int i = 0 ; i < v.size() ; i++){
      if(r < v[i].first){
        if(l!=0) pans.pb({l,r});
        l = v[i].first;
      }
      r = max(r,v[i].second);
    }
    pans.pb({l,r});
    vector<bool> ans(n+1,0);
    for(int i = 0 ; i < pans.size() ; i++){
      for(int j = pans[i].first ; j<= pans[i].second ; j++){
        ans[j] = 1;
      }
    }
    for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
    cout << endl;
  }
	return 0;
}