#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
ll n,m,p,g;
vector<pair<ll,ll>> adj[N];
ll d[N][N];
ll person[N];

void dij(ll s){
	priority_queue<pair<ll,ll>> q;
	d[s][s] = 0;
	q.push({0,s});
	while(!q.empty()){
		ll u = q.top().second;
		q.pop();
		for(auto v : adj[u]){
			ll vv = v.second, w = v.first;
			if(d[s][vv] > d[s][u] + w){
				d[s][vv] = d[s][u] + w;
				q.push({-d[s][vv],vv});
			}
		}
	}
}

int main(){
	FIO;
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < N ; j++){
      d[i][j] = ll(1e15);
    }
  }
	cin >> n >> m >> p >> g;
  for(int i = 0 ; i < p ; i++) cin >> person[i], person[i]--;

  for(int i = 0 ; i < m ; i++){
    ll a,b,c; cin >> a >> b >> c; a--, b--;
    adj[a].pb({c,b});
    adj[b].pb({c,a});
  }
  dij(0);
  for(int i = 0 ; i < p ; i++) dij(person[i]);

  ll ans = LLONG_MAX;
  for(int i = 0 ; i < n ; i++){
    ll currAns = 0;
    for(int j = 0 ; j < p ; j++){
      if(d[0][i] + d[person[j]][i] == d[0][person[j]]) currAns += min(g + d[person[j]][i], d[person[j]][0]);
      else currAns += d[person[j]][0];
    }
    ans = min(currAns,ans);
  }
  cout << ans << endl;
	return 0;
}