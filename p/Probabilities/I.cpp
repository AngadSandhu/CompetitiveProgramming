#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
vector<int> adj[N];
int n;
ll sz[N];
long double E[N];
void dfs1(int u,int p){
    sz[u] = 1;
    for(auto v : adj[u]){
        if(v==p) continue;
        dfs1(v,u);
        sz[u] += sz[v];
    }
}
void dfs2(int u,int p){
    if(u){
        E[u] = E[p] + 1 + 1.0*(sz[p]-sz[u]-1)/2.0;
    }else E[u] = 1;
    for(auto v : adj[u]){
        dfs2(v,u);
    }
}
int main(){
	FIO;
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int p; cin >> p; p--;
        adj[p].pb(i);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    cout << fixed << setprecision(7);
    for(int i = 0; i < n ; i++){
        cout << E[i];
        if(i<n) cout << " ";
    }
    cout << endl;
	return 0;
}
