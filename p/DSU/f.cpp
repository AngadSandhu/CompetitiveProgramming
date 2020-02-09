#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
ll const mod = 1e9 + 9;
ll const K = 31;
ll power[3*N];
vector<int> adj[N];
vector<ll> Hash[N];
ll queryHash;
int sp[20][N];
int par[N];
int spsum[20][N];
int dep[N];
int depchr[N];
string pal[N];
int n;
string query;

void hash_init(){
    dep[0] = 0;
    pal[0] = "";
    power[0] = 1;
    for(ll i = 1 ; i < 3*N ; i++){
        power[i] = (power[i-1]*K) % mod;
    }
    for(int i = 0 ; i < n ; i++){
        Hash[i].resize(pal[i].size()+1);
        Hash[i][0] = 0;
    }
    for(int i = 0 ; i < (int)query.size() ; i++){
        queryHash = ( queryHash*K + (query[i] - 'a' + 1) )%mod;
    }
}
void dfs_hash(int v,int p){
    if(v!=0){
        Hash[v][0] = Hash[p][pal[p].size()];
        for(int i = 1 ; i <= (int)pal[v].size() ; i++){
            Hash[v][i] = 0;
            Hash[v][i] = (Hash[v][i] + Hash[v][i-1]*K)%mod;
            Hash[v][i] = (Hash[v][i] + (pal[v][i-1] - 'a' + 1) )%mod;
        }
    }
    for(auto u : adj[v]){
        if(u==p) continue;
        dep[u] = dep[v] + 1;
        depchr[u] = depchr[v] + pal[u].size();
        dfs_hash(u,v);
    }
}
void sp_init(){
    par[0] = -1;
    for(int i = 0 ; i < n ; i++){
        spsum[0][i] = pal[i].size();
        sp[0][i] = par[i];
    }
}
void dfs_sp(int v,int p){
    for(int i = 1 ; (1<<i) <= dep[v] ; i++){
        spsum[i][v] = spsum[i-1][v] + spsum[i-1][sp[i-1][v]];
        sp[i][v] = sp[i-1][sp[i-1][v]];
    }
    for(auto u : adj[v]){
        if(u==p) continue;
        dfs_sp(u,v);
    }
}
int sol(int v){
    int sz;
    int sum = 0;
    int j = dep[v];
    int cur = v;
    int ret = 0;
    for(int i = 0 ; i < (int)pal[v].size() ; i++){
        sz = query.size();
        if((int)query.size() <= i+1){
            ll val = Hash[v][i+1] - Hash[v][i+1-sz]*power[sz];
            val %= mod;
            val += mod;
            val %= mod;
            if(val == queryHash) ret++;
            continue;
        }
        if(par[v]==0) continue;
        j = (int)log2(dep[par[v]]);
        cur = par[v];
        sum = i+1;
        while(j >= 0 && cur !=0){
            if(sum + spsum[j][cur] < sz) sum += spsum[j][cur], cur = sp[j][cur];
            j--;
        }
        if(cur == 0) continue;
        int x = sz - sum;
        x = pal[cur].size()-x-1;
        ll val = Hash[v][i+1] - Hash[cur][x+1]*power[sz];
        val %= mod;
        val += mod;
        val %= mod;
        if(val == queryHash){
            ret++;
        }
    }
    return ret;
}
int main(){
    cin >> n;
    int p;
    for(int i = 1 ; i < n ; i++){
        cin >> p >> pal[i];
        adj[--p].push_back(i);
        par[i] = p;
    }
    cin >> query;
    hash_init();
    dfs_hash(0,-1);
    sp_init();
    dfs_sp(0,-1);
    ll res = 0;
    for(int i = 1 ; i < n ; i++){
        res += sol(i);
    }
    cout << res << endl;
    return 0;
}