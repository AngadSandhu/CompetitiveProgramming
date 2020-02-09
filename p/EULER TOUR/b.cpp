#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005
ll in[N];
ll ans[N];
vector<int> adj[N];
int n,q;

void dfs(int v,int p,ll val){
    val += in[v];
    ans[v] += val;
    for(auto u : adj[v]){
        if(u!=p)
            dfs(u,v,val);
    }
    val -= in[v];
}
int main(){
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++) cin >> ans[i];
    for(int i = 0 ; i < n-1 ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0 ; i < q ; i++){
        int u,val;
        cin >> u >> val;
        in[--u] += val;
    }
    dfs(0,-1,0);
    for(int i = 0 ; i < n ; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}