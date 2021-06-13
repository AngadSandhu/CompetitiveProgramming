#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 20
#define EPS 0.000001
struct Grifo{
  ll t,a,b;
  void cinGrifo(){cin >> t >> a >> b;}
  Grifo(){};
};
Grifo g[N];
bool comp(Grifo g1, Grifo g2){
  return g1.t < g2.t;
}
int main(){
	FIO;
	ll k; cin >> k;
  for(int i = 0 ; i < k ; i++) g[i].cinGrifo();
  ll sumMinFlow = 0, sumTMin = 0;
  for(int i = 0 ; i < k ; i++) sumMinFlow += g[i].a, sumTMin += g[i].a*g[i].t;
  for(int i = 0 ; i < k ; i++) g[i].b -= g[i].a;
  sort(g,g+k,comp);
  int r; cin >> r;
  while(r--){
    ll tq, xq; cin >> tq >> xq;
    bool ans = 1;
    ll currFlow = xq - sumMinFlow;
    double tMin = sumTMin, tMax = sumTMin;
    for(int i = 0 ; i < k ; i++){
      tMin += max(0ll,g[i].t * min(currFlow,g[i].b));
      currFlow -= g[i].b;
    }
    if(currFlow > EPS) ans = 0;
    currFlow = xq - sumMinFlow;
    for(int i = k-1 ; i >= 0; i--){
      tMax += max(0ll,g[i].t * min(currFlow,g[i].b));
      currFlow -= g[i].b;
    }
    tMin /= xq, tMax /= xq;
    // cout << tMin << " " << tMax <<  " "  << tq << endl;
    if(sumMinFlow > xq) ans = 0;
    if(currFlow > EPS) ans = 0;
    if(tMin - EPS > tq || tq > tMax + EPS) ans = 0;
    cout << (ans ? "yes" : "no") << endl;
  }
	return 0;
}