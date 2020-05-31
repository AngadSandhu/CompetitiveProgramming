#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 505
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
void VertexCover(){
    L.clear();
    R.clear();
    for(int i = 1 ; i <= n ; i++){
        if(d[i]==INF) L.pb(i);
        else if(pl[i]!=0) R.pb(pl[i]);
    }
}
struct voter{
    char x1,x2; int y1,y2;
    voter(){};
    voter(char x1,char x2,int y1,int y2): x1(x1), x2(x2), y1(y1), y2(y2) {};
};
int ct,dg,v;
vector<voter> vot;
int num[N];
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> ct >> dg >> v;
        vot.resize(v);
        for(int i = 0 ; i < v ; i++){
            cin >> vot[i].x1 >> vot[i].y1 >> vot[i].x2 >> vot[i].y2;
            if(vot[i].x1 == 'C') num[i] = ++n;
            else num[i] = ++m;
        }
        for(int i = 0 ; i < v ; i++){
            if(vot[i].x1 == 'C')
            for(int j = 0; j < v ; j++){
                if(i==j) continue;
                if(vot[j].x2 == vot[i].x1 && vot[j].y2 == vot[i].y1) adj[num[i]].pb(num[j]);
                if(vot[j].x1 == vot[i].x2 && vot[j].y1 == vot[i].y2) adj[num[i]].pb(num[j]);
            }
        }
        cout << v - HopcroftKarp() << endl;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        n = m = 0;
    }
	return 0;
}