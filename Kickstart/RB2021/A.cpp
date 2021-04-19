#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  int caso = 0;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1;
    cout << "Case #" << ++caso << ": ";
    cout << ans << " ";
    for(int i = 1 ;i < n ; i++){
      if(s[i] > s[i-1]) ans++;
      else ans = 1;
      cout << ans << " ";
    }
    cout << endl;
  }
	return 0;
}