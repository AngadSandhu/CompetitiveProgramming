#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 505
#define INF INT_MAX
struct person{
    int h;
    char sex;
    string music,sport;
    person(){};
    person(int h,char sex,string music,string sport): h(h), sex(sex),music(music), sport(sport){};
};
int n,m;
vector<int> adj[N];
vector<int> L,R;
bool visit[N];
int pl[N], pr[N], d[N];
vector<person> p1,p2;
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
void HopcroftKarp(){
    for(int i = 0 ; i <= n ; i++) pl[i] = 0;
    for(int i = 0 ; i <= m ; i++) pr[i] = 0;
    int match = 0;
    while(bfs()){
        for(int i = 1; i <= n; i++) {
            if(pl[i]==0 && dfs(i)) match++;
        }
    }
}
int VertexCover(){
    L.clear();
    R.clear();
    for(int i = 1 ; i <= n ; i++){
        if(d[i]==INF) L.pb(i);
        else if(pl[i]!=0) R.pb(pl[i]);
    }
    return L.size() + R.size();
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            person p; cin >> p.h >> p.sex >> p.music >> p.sport;
            if(p.sex == 'M') p1.pb(p);
            else p2.pb(p);
        }
        n = p1.size();
        m = p2.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(abs(p1[i].h-p2[j].h) <= 40 && p1[i].music == p2[j].music && p1[i].sport != p2[j].sport) adj[i+1].pb(j+1);
            }
        }
        HopcroftKarp();
        cout << n+m-VertexCover() << endl;
        for(int i = 0 ; i <= n ; i++) adj[i].clear();
        p1.clear(); p2.clear();
    }
	return 0;
}