#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
#define M 10005
#define nodos 26*10000+5
char a[N],b[N];
int sza,szb;
ll sa[N], sb[N];
char d[M][26], s[26];
int dsz[M], val[M], m, len, quitar1[N],quitar2[N];
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
	int t; scanf("%d",&t);
    while(t--){
        scanf("%s %s",a,b);
        scanf("%d",&m);
        sza = strlen(a), szb = strlen(b);
        for(int i = 0 ; i < m ; i++){
            scanf("%s %d",d[i], &val[i]);
            dsz[i] = strlen(d[i]);
        }
        aho_corasick();
        len = 0;
        for(int i = 0 ; i < sza ; i++){
            s[len++] = a[i];
            sa[i] = get(1);
        }
        len = 0;
        for(int i = szb-1 ; i >= 0 ; i--){
            s[len++] = b[i];
            sb[i] = get(0);
        }
        for(int i = 0 ; i < sza ; i++){
            len = 0;
            for(int k = max(0,i-26) ; k <= i ; k++) s[len++] = a[k];
            quitar1[i] = get(1);
        }
        for(int i = 0 ; i < szb ; i++){
            len = 0;
            for(int k = i ; k-i+1 <= 26 && k < szb; k++) s[len++] = b[k];
            quitar2[i] = get(1);
        }
        ll res = 0;
        for(int i = 0 ; i < sza ; i++){
            for(int j = 0 ; j < szb ; j++){
                len = 0;
                for(int k = max(0,i-26) ; k <= i ; k++) s[len++] = a[k];
                for(int k = j ; k-j+1 <= 26 && k < szb; k++) s[len++] = b[k];
                res = max(res,sa[i] + sb[j] + get(1) - quitar1[i] - quitar2[j]);
            }
        }
        cout << res << "\n";
        for(int i = 0 ; i < nodes ; i++){
            ter[i] = 0;
            fill(nxt[i],nxt[i]+26,-1);
            fill(go[i],go[i]+26,-1);
            f[i] = -1;
        }
        nodes = 1;
    }
	return 0;
}