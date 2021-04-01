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
    int n,k1,k2; cin >> n >> k1 >> k2;
    int w,b; cin >> w >> b;
    if(k1 < k2) swap(k1,k2);
    int havew = k2 + (k1-k2)/2;
    int y1 = n-k1, y2 = n-k2;
    if(y1 < y2) swap(y1,y2);
    int haveb = y2 + (y1-y2)/2;
    if(havew >= w && haveb >= b) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
	return 0;
}