#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
vector<int> adj[N];
vector<int> vec[N];
set<string> cnt[N];
map<string,int> multicnt[N];
vector<pair<int,int>> query[N];
string pal[N];
int n,m;
int sz[N],dep[N];
int res[N];
bool visit[N];
void dfs_init(int v){
    visit[v] = 1;
    sz[v] = 1;
    for(int u : adj[v]){
        dep[u] = dep[v] + 1;
        dfs_init(u);
        sz[v] += sz[u];
    }
}
void dfs(int v,bool keep){
    int mx = -1, bigchild = -1;
    visit[v] = 1;
    for(auto u : adj[v]){
        if(mx < sz[u]){
            mx = sz[u];
            bigchild = u;
        }
    }
    for(auto u : adj[v]){
        if(u!=bigchild)
            dfs(u,0);
    }
    if(bigchild!=-1){
        dfs(bigchild,1);
        swap(vec[v],vec[bigchild]);
    }
    cnt[dep[v]].insert(pal[v]);
    multicnt[dep[v]][pal[v]]++;
    vec[v].push_back(v);
    for(auto u : adj[v]){
        if(u==bigchild) continue;
        for(auto x : vec[u]){
            cnt[dep[x]].insert(pal[x]);
            multicnt[dep[x]][pal[x]]++;
            vec[v].push_back(x);
        }
    }
    for(auto q : query[v]){
        if(q.second + dep[v] > n) res[q.first] = 0;
        else res[q.first] = cnt[q.second+dep[v]].size();
    }
    if(keep==0){
        for(auto x : vec[v]){
            if(multicnt[dep[x]][pal[x]] == 1)
                cnt[dep[x]].erase(pal[x]);
            multicnt[dep[x]][pal[x]]--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int r;
    for(int i = 0 ; i < n ; i++){
        cin >> pal[i] >> r;
        r--;
        if(r!=-1) adj[r].push_back(i);
    }
    cin >> m;
    int v,k;
    for(int i = 0 ;i < m ; i++){
        cin >> v >> k; v--;
        query[v].push_back({i,k});
    }
    for(int i = 0 ; i < n ; i++){
        if(visit[i]==0) dep[i] = 1, dfs_init(i);
    }
    memset(visit,0,sizeof visit);
    for(int i = 0 ; i < n ; i++){
        if(visit[i]==0) dfs(i,0);
    }
    for(int i = 0 ; i < m ; i++){
        cout << res[i] << endl;
    }
    return 0;
}