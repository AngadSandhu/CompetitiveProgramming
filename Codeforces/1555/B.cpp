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
    int W,H; cin >> W >> H;
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int w,h; cin >> w >> h;
    int tw = x2-x1,th = y2-y1;
    if(tw + w > W && th + h > H){
      cout << -1 << endl;
      continue;
    }
    int ans = INT_MAX;
    if(th + h <= H) ans = min(ans, max(0,h-y1));
    if(th + h <= H)ans = min(ans, max(0,y2-(H-h)));
    if(tw + w <= W)ans = min(ans, max(0,w-x1));
    if(tw + w <= W)ans = min(ans, max(0,x2-(W-w)));
    cout << ans << endl;
  }
	return 0;
}