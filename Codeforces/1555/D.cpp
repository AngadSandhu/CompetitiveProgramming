#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int pref[6][N];
int main(){
	FIO;
	int n,m; cin >> n >> m;
  string s; cin >> s;
  string t = "abc";
  int cur = 0;
  do {
    for (int i = 0; i < n; ++i)
      pref[cur][i + 1] = pref[cur][i] + (s[i] != t[i % 3]);
    ++cur;
  } while (next_permutation(t.begin(), t.end()));
  while(m--){
    int l,r; cin >> l >> r;
    int ans = INT_MAX;
    for(int i = 0 ; i < 6 ; i++) ans = min(ans, pref[i][r] - pref[i][l-1]);
    cout << ans << endl;
  }
	return 0;
}