#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500001
vector<int> adj[N];
vector<int> vec[N];
vector<pair<int,int>> query[N];
bool res[N];
int cntdep[30][N],cntimpdep[N];
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
void change(vector<int> &aux,int &v,int id){
    int lt,dp;
    for(int x : aux){
        lt = let[x] - 'a';
        dp = dep[x];
        cntdep[lt][dp]+=id;
        if(id==1) vec[v].push_back(x);
        if(cntdep[lt][dp]%2){
            cntimpdep[dp]++;
        }else{
            cntimpdep[dp]--;
        }
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
    }
    vector<int> xs(1,v);
    change(xs,v,1);
    for(int u : adj[v]){
        if(u==bigchild) continue;
        change(vec[u],v,1);
    }
    for(auto &depi : query[v]){
        res[depi.first] = cntimpdep[depi.second] <= 1 ;
    }
    if(keep==0){
        change(vec[v],v,-1);
    }
}
int main(){
    dep[0] = 1;
    scanf("%d %d",&n,&m);
    int u,v,h;
    for(int i = 1 ; i < n ; i++){
        scanf("%d",&u); u--;
        adj[u].push_back(i);
    }
    scanf("%s",let);
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d",&v,&h);
        v--;
        query[v].push_back({i,h});
    }
    dfs_init(0,-1);
    dfs(0,-1,1);
    for(int i = 0 ; i < m ; i++){
        if(res[i]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}