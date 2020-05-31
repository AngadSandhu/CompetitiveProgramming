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
void ford(){
    fill(pl,pl+n,-1);
    fill(pr,pr+n,-1);
    bool found = 1;
    while(found){
        found = 0;
        fill(visit,visit+n,0);
        for(int i = 0 ; i < n ; i++){
            if(pl[i] == -1 && aug(i)) {
                found = 1;
                break;
            }
        }
    }
}