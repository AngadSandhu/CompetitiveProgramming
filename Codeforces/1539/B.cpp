#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int frec[N][27];
int main(){
	FIO;
  int n,q; cin >> n >> q;
  string s; cin >> s;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 0 ; j < 26 ; j++){
      frec[i][j] = frec[i-1][j];
    }
    frec[i][s[i-1]-'a']++;
  }
  for(int i = 0 ; i < q ; i++){
    int x,y; cin >> x >> y;
    int ans = 0;
    for(int j = 0 ; j < 26 ; j++){
      ans += (j+1)*(frec[y][j] - frec[x-1][j]);
    }
    cout << ans << endl;
  }	
	return 0;
}