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
    vector<int> a(n), b(n);
    ll s1 = 0, s2 = 0;
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = n/4 ; i < n ; i++){
      s2 += b[i];
      s1 += a[i];
    }
    if(s1 >= s2){
      cout << 0 << endl;
      continue;
    }
    int cnt = 0, j = n/4-1;
    while(s1 < s2){
      //cout << s1 << " " << s2 << endl;
      s1 += 100;
      if(j >= 0) s2 += b[j];
      j--;
      cnt++;
      a.pb(100);
      if(a.size()%4 == 0){
        s1 -= a[a.size()/4-1];
        if(j >= -1) j++, s2 -= b[j];
      }
    }
    cout << cnt << endl;
  }
	return 0;
}