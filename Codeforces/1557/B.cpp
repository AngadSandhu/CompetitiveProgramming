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
    vector<pair<int,int>> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(),a.end());
    int used = 0;
    for(int i = 0 ; i < n-1 ; i++){
      used += a[i].second+1 != a[i+1].second;
    }
    cout << (used <= k-1 ? "Yes" : "No") << endl;
  }
	return 0;
}