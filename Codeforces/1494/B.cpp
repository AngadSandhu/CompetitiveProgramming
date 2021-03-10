#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n, u, r, d ,l;
bool bit(int x, int p){
  return (x>>p)&1;
}
bool valid(int mask){
  int nu = u - bit(mask,0) - bit(mask,1),
   nr = r - bit(mask,1) - bit(mask,2), 
   nd = d - bit(mask,2) - bit(mask,3) ,
   nl = l - bit(mask,3) - bit(mask,0);

   return (nu >=0 && nu <= n-2) && 
   (nl >=0 && nl <= n-2) && 
   (nr >=0 && nr <= n-2) && 
   (nd >=0 && nd <= n-2);
}

int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n >> u >> r >> d >> l;
    bool ans = 0;
    for(int i = 0 ; i < (1<<4) ; i ++){
      ans |= valid(i);
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
	return 0;
}