#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 50005
vector<int> adj[N];
multiset<int> vec[N];
int res[N];
int val[N];
int sz[N],dep[N];
int n,m;
void dfs_init(int v,int p){
    sz[v] = 1;
    for(int u : adj[v]){
        dep[u] = dep[v] + 1;
        dfs_init(u,v);
        sz[v] += sz[u];
    }
}
void change(int &u,int &v){
    int mn;
    for(int x : vec[u]){
        auto it = vec[v].lower_bound(x);
        if(it==vec[v].end()){
            mn = abs(*(--it) - x);
        }else if(it==vec[v].begin()){
            mn = abs(*it - x);
        }else{
            int val1 = abs(*it-x), val2 = abs(*(--it)-x);
            mn = min(val1,val2);
        }
        if(res[v] > mn){
            res[v] = mn;
        }
        vec[v].insert(x);
    }
}
void dfs(int v,int p){
    int mx = -1, bigchild = -1;
    for(int u : adj[v]){
        if(sz[u] > mx){
            mx = sz[u];
            bigchild = u;
        }
    }
    for(int u : adj[v]){
        if(u==bigchild) continue;
        dfs(u,v);
    }
    if(bigchild !=-1){
        dfs(bigchild,v);
        swap(vec[v],vec[bigchild]);
        res[v] = res[bigchild];
    }else{
        vec[v].insert(val[v]);
    }
    for(int u : adj[v]){
        if(u==bigchild) continue;
        change(u,v);
    }
}
int main(){
    dep[0] = 1;
    scanf("%d %d",&n,&m);
    fill(res,res+n,INT_MAX);
    int u;
    for(int i = 1 ; i < n ; i++){
        scanf("%d",&u); u--;
        adj[u].push_back(i);
    }
    for(int i = n-m ; i < n ; i++){
        scanf("%d",&val[i]);
        val[i] += 100;
    }
    dfs_init(0,-1);
    dfs(0,-1);
    for(int i = 0 ; i < n-m ; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}