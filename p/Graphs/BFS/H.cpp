#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;
#define pb push_back
#define N 1005
int n,p,k;
int d[N];
vector<pair<int,int> > adj[N];
int countGreater(int x){
  for(int i = 0 ; i < N ; i++) d[i] = (1<<30);
  deque<int> q;
  d[0] = 0;
  q.push_front(0);
  while(!q.empty()){
    int u = q.front();
    q.pop_front();
    for(int i = 0 ; i < adj[u].size() ; i++){
      pair<int,int> v = adj[u][i];
      if(d[u] + (v.second >x) >= d[v.first]) continue;
      d[v.first] = d[u] + (v.second>x);
      if(v.second > x) q.push_back(v.first);
      else q.push_front(v.first);
    }
  }
  return d[n-1];
}
int solve(){
  int l = 0, r = 1000005, med;
  while(l < r){
    med = (r+l)/2;
    if(countGreater(med) <= k) r = med;
    else l = med+1;
  }
  if(l==1000005) return -1;
  else return l;
}
int main(){
	cin >> n >> p >> k;
  int x,y,w;
  for(int i = 0 ; i < p ; i++){
    cin >> x >> y >> w;
    x--,y--;
    adj[x].pb({y,w});
    adj[y].pb({x,w});
  }
  cout << solve()<< endl;
	return 0;
}
