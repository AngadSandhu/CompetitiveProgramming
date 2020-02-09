#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300005

vector<int> adj[N];
int res[N];
int sz[N],dep[N];
int maxsz[N];
int p[N];
int n,q;
bool cumple(int u,int v){
    return 2*max(maxsz[u],sz[v]-sz[u]) <= sz[v];
}
void dfs(int v){
    int mx = 0, bigchild = -1;
    sz[v] = 1;
    for(auto u : adj[v]){
        dfs(u);
        sz[v] += sz[u];
        if(mx < sz[u]){
            mx = sz[u];
            bigchild = u;
        }
    }
    maxsz[v] = mx;
    int cur;
    if(bigchild==-1) cur = v;
    else cur = res[bigchild];
    while(!cumple(cur,v)){
        cur = p[cur];
    }
    res[v] = cur;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    int v;
    p[0] = -1;
    for(int i = 1 ; i < n ; i++){
        cin >> v;
        v--;
        adj[v].push_back(i);
        p[i] = v;
    }
    dfs(0);
    for(int i = 0 ; i < q ; i++){
        cin >> v; v--;
        cout << res[v]+1 << endl;
    }
}