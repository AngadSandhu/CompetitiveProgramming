int nxt[nodos][26], ter[nodos], f[nodos], go[nodos][26], nodes = 1;
void aho_corasick(){
    for(int i = 0 ; i < m ; i++){
        int cur = 0;
        for(int j = 0, c ; j < dsz[i] ; j++){
            c = d[i][j]-'a';
            if(nxt[cur][c] == -1) nxt[cur][c] = nodes++;
            cur = nxt[cur][c];
        }
        ter[cur] += val[i];
    }
    for(int i = 0 ; i < 26 ; i++) if(nxt[0][i]==-1) nxt[0][i] = 0;
    queue<int> q;
    for(int i = 0 ; i < 26 ; i++){
        if(nxt[0][i] != 0) f[nxt[0][i]] = 0, q.push(nxt[0][i]);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0 ; i < 26 ; i++){
            if(nxt[cur][i] == -1) continue;
            int fail = f[cur];
            while(nxt[fail][i] == -1) fail = f[fail];
            fail = nxt[fail][i];
            f[nxt[cur][i]] = fail;
            ter[nxt[cur][i]] += ter[fail];
            q.push(nxt[cur][i]);
        }
    }
}
inline int gof(int cur,char ch){
    if(go[cur][ch-'a'] != -1) return go[cur][ch-'a'];
    int ret = cur, c = ch-'a';
    while(nxt[ret][c] == -1) ret = f[ret];
    return go[cur][c] = nxt[ret][c];
}
ll get(bool y){
    int cur = 0;
    ll ret = 0;
    for(int i = 0 ; i < len ; i++){
        cur = gof(cur,s[(y? i : len-i-1)]);
        ret += ter[cur];
    }
    return ret;
}
int main(){
    memset(nxt,-1,sizeof nxt);
    memset(f,-1,sizeof f);
    memset(go,-1,sizeof go);
}