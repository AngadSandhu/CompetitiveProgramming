#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1010
#define EPS 1e-5
vector<pair<double,double>> dot;
int x,y;
int n; 
double distance(int i,int j){
  return sqrt((dot[i].first-dot[j].first)*(dot[i].first-dot[j].first)
              + (dot[i].second-dot[j].second)*(dot[i].second-dot[j].second));
}
bool intersects(int i, int j, double radio){
  return distance(i,j) < 2*radio;
}
int par[N], sz[N];
int Find(int u){
  if(u == par[u]) return u;
  return par[u] = Find(par[u]);
}
void onion(int u,int v){
  if(sz[u] < sz[v]) swap(u,v);
  par[v] = u;
  sz[u] += sz[v];
}
bool f(double R){
  for(int i = 0 ; i < n+4 ; i++) sz[i] = 1, par[i] = i;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(intersects(i,j,R) && Find(j) != Find(i)) onion(Find(i),Find(j));
    }
  }
  for(int i = 0 ; i < n ; i++){
    if(dot[i].second - R <= 0 && Find(n) != Find(i)) onion(Find(n),Find(i));
    if(dot[i].second + R >= y && Find(n+1) != Find(i)) onion(Find(n+1),Find(i));
    if(dot[i].first - R <= 0 && Find(n+2) != Find(i)) onion(Find(n+2),Find(i));
    if(dot[i].first + R >= x && Find(n+3) != Find(i)) onion(Find(n+3),Find(i));
  }
  if(Find(n) == Find(n+1) || Find(n+2) == Find(n+3) || Find(n+2) == Find(n) || Find(n+1) == Find(n+3)) return false;
  return true;
}
double solve(){
  double l = 0, r = 3000000, med;
  while((r-l) > EPS){
    med = (l+r)/2;
    if(f(med)) l = med;
    else r = med;
  }
  return l;
}
int main(){
	FIO;
	cin >> x >> y;
  cin >> n;
  dot.resize(n);
  for(int i = 0; i < n ; i++){
    cin >> dot[i].first >> dot[i].second;
  }
  cout << fixed << setprecision(5) << solve()  << endl;
	return 0;
}