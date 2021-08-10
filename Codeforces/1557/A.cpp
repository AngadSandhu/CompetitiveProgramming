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
    vector<int> a(n);
    for(int &i:a) cin >> i;
    sort(a.begin(),a.end());
    double ans = 0;
    for(int i = 0 ; i < n-1; i++){
      ans += a[i];
    }
    ans /= (n-1);
    ans += a.back();
    cout << fixed << setprecision(6) << ans  << endl;
  }
	return 0;
}