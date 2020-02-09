#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int sz[N];
vector<int> adj[N];
vector<int> vec[N];
ll color[N],cnt[N];
ll maxsum[N],maxi[N];
int n;
void sizedfs(int v,int p){
    sz[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        sizedfs(u,v);
        sz[v] += sz[u];
    }
}

void dfs(int v,int p,bool keep){
    int mx = -1, bigchild = -1;
    for(auto u : adj[v]){
        if(u==p) continue;
        if(mx < sz[u]){
            mx = sz[u];
            bigchild = u;
        }
    }
    for(auto u : adj[v]){
        if(u==p || u==bigchild) continue;
        dfs(u,v,0);
    }
    if(bigchild != -1){
        dfs(bigchild,v,1);
        swap(vec[v],vec[bigchild]);
        maxsum[v] = maxsum[bigchild];
        maxi[v] = maxi[bigchild];
    }
    cnt[color[v]]++;
    vec[v].push_back(v);
    
    if(cnt[color[v]] == maxi[v]){
        maxsum[v] += color[v];
    }else if(cnt[color[v]] > maxi[v]){
        maxi[v] = cnt[color[v]];
        maxsum[v] = color[v];
    }
    for(auto u : adj[v]){
        if(u==p || u==bigchild) continue;
        for(auto x : vec[u]){
            cnt[color[x]]++;
            vec[v].push_back(x);
            if(cnt[color[x]] == maxi[v]){
                maxsum[v] += color[x];
            }else if(cnt[color[x]] > maxi[v]){
                maxi[v] = cnt[color[x]];
                maxsum[v] = color[x];
            }
        }
    }
    if(keep==0){
        for(auto u : vec[v]){
            cnt[color[u]]--;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> color[i];
    int u,v;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sizedfs(0,-1);
    dfs(0,-1,1);
    for(int i = 0 ; i < n ; i++){
        cout << maxsum[i] << " ";
    }
    cout << endl;
    return 0;
}