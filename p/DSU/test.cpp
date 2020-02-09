#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500001
vector<int> adj[N];
set<int> vec[N];
vector<pair<int,int>> query[N];
int res[N];
int val[N];
int sz[N],dep[N];
char let[N];
int n,m;
void dfs_init(int v,int p){
    sz[v] = 1;
    for(int u : adj[v]){
        dep[u] = dep[v] + 1;
        dfs_init(u,v);
        sz[v] += sz[u];
    }
}
void change(set<int> &aux,int &v,int id){
    int mx;
    set<int>::iterator it;
    for(auto x : aux){
        it = vec[v].lower_bound(x);
        if(it==vec[v].end()){
            mx = abs(*(it--) - x);
        }else{
            mx = max(abs(*it-x),abs(*(it--)-x));
        }
        if(res[v] < mx){
            res[v] = mx;
        }
        vec[v].insert(x);
    }
}
void dfs(int v,int p,bool keep){
    int mx = -1, bigchild = -1;
    for(int u : adj[v]){
        if(sz[u] > mx){
            mx = sz[u];
            bigchild = u;
        }
    }
    for(int u : adj[v]){
        if(u==bigchild) continue;
        dfs(u,v,0);
    }
    if(bigchild !=-1){
        dfs(bigchild,v,1);
        swap(vec[v],vec[bigchild]);
    }else{
        vec[v].insert(val[v]);
    }
    for(int u : adj[v]){
        if(u==bigchild) continue;
        change(vec[u],v,1);
    }
    if(keep==0){
        change(vec[v],v,-1);
    }
}
int main(){
    memset(res,-1,sizeof res);
    dep[0] = 1;
    scanf("%d %d",&n,&m);
    int u,v,h;
    for(int i = 1 ; i < n ; i++){
        scanf("%d",&u); u--;
        adj[u].push_back(i);
    }
    for(int i = n-m ; i < n ; i++){
        scanf("%d",&val[i]);
    }
    dfs_init(0,-1);
    dfs(0,-1,1);
    for(int i = 0 ; i < n-m ; i++){
        cout << res[i] << endl;
    }
    return 0;
}