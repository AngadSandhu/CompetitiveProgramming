#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
#define INF INT_MAX
int n,m;
vector<int> adj[N];
vector<int> L,R;
bool visit[N];
int pl[N], pr[N], d[N];
bool bfs() {
    queue<int> q;
    for(int i = 1 ; i <= n; i++){
        if(pl[i] == 0) d[i] = 0, q.push(i);
        else d[i] = INF;
    }
    d[0] = INF;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(d[u] >= d[0]) continue;
        for(auto v : adj[u]) {
            if(d[pr[v]] != INF) continue;
            d[pr[v]] = d[u] + 1;
            q.push(pr[v]);
        }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if(u == 0) return true;
    for(auto v : adj[u]) {
        if(d[pr[v]] == d[u] + 1) {
            if(dfs(pr[v])) {
                pl[u] = v;
                pr[v] = u;
                return true;
            }
        }
    }
    d[u] = INF;
    return false;
}
int HopcroftKarp(){
    for(int i = 0 ; i <= n ; i++) pl[i] = 0;
    for(int i = 0 ; i <= m ; i++) pr[i] = 0;
    int match = 0;
    while(bfs()){
        for(int i = 1; i <= n; i++) {
            if(pl[i]==0 && dfs(i)) match++;
        }
    }
    return match;
}
long double dist(pair<int,int> &p1,pair<int,int> &p2){
    int x = p1.first-p2.first, y = p1.second - p2.second;
    return sqrt(x*x + y*y);
}
pair<int,int> pat[N], patin[N];
int main(){
	FIO;
	int t; cin >> t;
    int caso = 0;
    while(t--){
        if(caso++) cout << "\n";
        cin >> n >> m;
        for(int i = 1 ; i <= n ; i++) cin >> pat[i].first >> pat[i].second;
        for(int i = 1 ; i <= m ; i++) cin >> patin[i].first >> patin[i].second;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(2*dist(pat[i],pat[i+1]) + 1e-9 >= (dist(pat[i],patin[j]) + dist(patin[j],pat[i+1]) )) adj[i].pb(j);
            }
        }
        cout << n + HopcroftKarp() << endl;
        vector<pair<int,int>> ans;
        for(int i = 1 ; i < n ; i++){
            ans.pb(pat[i]);
            if(pl[i] != 0) ans.pb(patin[pl[i]]);
        }
        ans.pb(pat[n]);
        for(int i = 0 ; i < ans.size() ; i++){
            if(i) cout << " ";
            cout << ans[i].first << " " << ans[i].second;
        }
        cout << endl;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
    }
	return 0;
}