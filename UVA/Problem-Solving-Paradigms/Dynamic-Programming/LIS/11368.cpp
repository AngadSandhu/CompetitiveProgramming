#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(j==d.size()) d.pb(a[i]);
        else d[j] = a[i];
    }
    return d.size();
}

int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i].first >> a[i].second ,a[i].second *= -1;
    sort(a.begin(),a.end());
    vector<int> toLis(n);
    int ans = 0;
    for(int i = 0 ; i < n ; i++) toLis[i] = -a[i].second;
    reverse(toLis.begin(),toLis.end());
    ans = max(ans,lis(toLis));

    cout << ans << endl;
  }
	return 0;
}