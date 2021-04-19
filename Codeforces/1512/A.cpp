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
    vector<pair<int,int>> a;
    for(int i = 0 ; i < n ; i++){
      int x; cin >> x;
      a.pb({x,i+1});
    }
    sort(a.begin(),a.end());
    if(a[0].first == a[1].first) cout << a.back().second << endl;
    else cout << a[0].second << endl;
  }
	return 0;
}