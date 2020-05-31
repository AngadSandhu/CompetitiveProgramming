#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 305
#define INF INT_MAX
int n,m;
vector<int> adj[N];
vector<int> L,R;
bool visit[N];
int pl[N], pr[N], d[N];
bool bfs(){
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
int k;
map<string,vector<int>> recep;
string p[N], r[N];
map<string,vector<string>> adj2;
set<string> vs;
void dfs2(int s, string u){
    vs.insert(u);
    if(recep.count(u)>0){
        vector<int> &aux = recep[u];
        for(int v : aux) adj[s].pb(v);
    }
    for(string v : adj2[u]){
        if(vs.count(v)==0) dfs2(s,v);
    }
}
int main(){
	FIO;
    int t, caso = 0; cin >> t;
    while(t--){
        if(caso++) cout << "\n";
        cin >> m;
        for(int i = 1 ; i <= m ; i++){
            cin >> r[i];
            recep[r[i]].pb(i);
        }
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> p[i] >> p[i];
        }
        int q;
        cin >> q;
        for(int i = 0 ; i < q ; i++){
            string x,y; cin >> x >> y;
            adj2[x].pb(y);
        }
        for(int i = 1 ; i <= n ; i++){
            vs.clear();
            dfs2(i,p[i]);
        }
        cout << n - HopcroftKarp() << endl;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        adj2.clear();
        recep.clear();
    }
	return 0;
}