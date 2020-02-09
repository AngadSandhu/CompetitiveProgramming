#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
ll d[N];
int in[N];
int depet[3*N];
int dep[N];
vector<pair<int,ll>> adj[N];
int et[3*N];
int temp;
int RM[20][3*N],RMid[20][3*N];
int n,m,q;

void dfs(int v,int p){
    in[v] = temp;
    et[temp++] = v;
    for(auto u : adj[v]){
        if(u.first==p) continue;
        d[u.first] = d[v] + u.second;
        dep[u.first] = dep[v] + 1;
        dfs(u.first,v);
        et[temp++] = v;
    }
}
void rmq(){
    for(int i = 0 ; i < q ;i ++){
        depet[i] = dep[et[i]];
        RM[0][i] = depet[i];
        RMid[0][i] = et[i];
    }
    for(int j = 1 ; (1<<j) < q ; j++){
        for(int i = 0 ; i + (1<<j) < q ; i++){
            if(RM[j-1][i] < RM[j-1][i + (1<<(j-1)) ]) RMid[j][i] = RMid[j-1][i];
            else RMid[j][i] = RMid[j-1][i + (1<<(j-1)) ];
            RM[j][i] = min(RM[j-1][i],RM[j-1][i + (1<<(j-1)) ]);
        }
    }
}
int lca(int u,int v){
    int l = in[u], r = in[v];
    if(l > r) swap(l,r);
    int b = 31 - __builtin_clz(r-l+1);
    int id1 = RMid[b][l];
    int id2 = RMid[b][r - (1<<b) + 1];
    if(RM[b][l] < RM[b][r - (1<<b) + 1]) return id1;
    else return id2;
}
int main(){
    while(cin >> n, n > 0){
        temp = 0;
        for(int i = 0 ; i < n ; i++) adj[i].clear(),d[i] = 0,dep[i] = 0;
        for(int i = 1 ; i < n ; i++){
            int u,w; cin >> u >> w;
            adj[u].push_back({i,w});
            adj[i].push_back({u,w});
        }
        dfs(0,0);
        q = temp;
        rmq();
        
        cin >> m;
        while(m--){
            int s,t; cin >> s >> t;
            cout << d[s] + d[t] - 2*d[lca(s,t)];
            if(m>0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}