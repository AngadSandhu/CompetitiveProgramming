#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int a[2][N];
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int m; cin >> m;
    for(int i = 0; i < m; i ++) cin >> a[0][i];
    for(int i = 0; i < m; i ++) cin >> a[1][i];
    vector<int> pref(m+1), suf(m+2);
    pref[0] = 0;
    for(int i = 0 ; i < m ; i++){
      pref[i+1] = pref[i] + a[1][i];
    }
    suf[m+1] = 0;
    for(int i = m ; i >= 0 ; i--){
      suf[i] = suf[i+1] + a[0][i-1];
    }
    int mini = INT_MAX;
    for(int i = 1 ; i <= m ; i++){
      mini = min(mini,max(pref[i-1],suf[i+1]));
    }
    cout << mini << endl;
  }
	return 0;
}