#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1008
#define INF INT_MAX
int n,m,e;
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
void VertexCover(){
    L.clear();
    R.clear();
    for(int i = 1 ; i <= n ; i++){
        if(d[i]==INF) L.pb(i);
        else if(pl[i]!=0) R.pb(pl[i]);
    }
}

int main(){
    while(cin >> n >> m >> e , n > 0){
        for(int i = 0 ; i < e ; i++){
            int x,y; cin >> x >> y;
            adj[x].pb(y);
        }
        cout << HopcroftKarp();
        VertexCover();
        for(int i = 0 ; i < (int)L.size() ; i++){
            cout << " ";
            cout << "r" << L[i];
        }
        for(int i = 0 ; i < (int)R.size() ; i++){
            cout << " ";
            cout << "c" << R[i];
        }
        cout << endl;
        for(int i = 1 ; i <= n ; i++) adj[i].clear();
    }
}
