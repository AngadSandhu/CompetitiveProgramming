#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int n,m;
vector<int> adj[N];
int d[N];
void bfs(int s){
  memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(d[v]==-1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	FIO;
	cin >> n >> m;
  int x,y;
  for(int i = 0 ; i < m ; i++){
    cin >> x >> y;
    x--,y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  bfs(0);
  int maxi = 0, maxiId;
  for(int i = 0 ; i < n ; i++){
    if(d[i] != -1 && maxi < d[i]) maxi = d[i], maxiId = i;
  }
  bfs(maxiId);
  bool notFound = 0;
  maxi = 0;
  for(int i = 0 ; i < n ; i++){
    if(d[i] == -1) notFound = 1;
    else maxi = max(maxi,d[i]);
  }
  maxi = ceil(log2(maxi));
  cout << (notFound ? -1: maxi+1) << endl;
	return 0;
}