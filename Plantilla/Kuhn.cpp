int pl[N], pr[N];
int n;
vector<int> adj[N];
bool visit[N];
bool aug(int u){
    if(visit[u]) return false;
    visit[u] = 1;
    for(auto v : adj[u]){
        if(pr[v] == -1 || aug(pr[v])){
            pl[u] = v;
            pr[v] = u;
            return true;
        }
    }
    return false;
}
void kuhn(){
    fill(pl,pl+n,-1);
    fill(pr,pr+m,-1);
    //Greedy init
    for(int i = 0 ; i < n ; i++){
        if(pl[i]==-1){
            for(auto j : adj[i]){
                if(pr[j]== -1){
                    pl[i] = j;
                    pr[j] = i;
                    break;
                }
            }
        }
    }
    //Algorithm
    for(int i = 0 ; i < n ; i++){
        if(pl[i] == -1){
            fill(visit,visit+n,0);
            aug(i);
        }
    }
}
int match(){
    kuhn();
    int ret = 0;
    for(int i = 0 ; i < n ; i++) ret += (pl[i]!=-1);
    return ret;
}
void MVC(){
    fill(visit,visit+n,0);
    for(int i = 0 ; i < n ; i++){
        if(pl[i]==-1){
            dfs(i);
        }
    }
    // UNION
    // y tq y belongs to R and p[x] == y
    // x tq visit[x] == 0
}