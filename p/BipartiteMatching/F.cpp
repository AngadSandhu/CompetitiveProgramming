#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 500
#define M 50
#define INF INT_MAX
int n,m;
vector<int> adj[N];
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
int w,h;
char grilla[N][N];
int num[M][M];
int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> h >> w;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> grilla[i][j];
            }
        }
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(grilla[i][j] == 'o') continue;
                if((i+j)%2==0) num[i][j] = ++n;
                else num[i][j] = ++m;
            }
        }
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(grilla[i][j]=='o' || (i+j)%2) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int nr = i + dr[k], nc = j + dc[k]; 
                    if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                    if(grilla[nr][nc]=='*') adj[num[i][j]].pb(num[nr][nc]);
                }
            }
        }
        cout << n+m-HopcroftKarp() << endl;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        memset(num,0,sizeof num);
        n = m = 0;
    }
	return 0;
}