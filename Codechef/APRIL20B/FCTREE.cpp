#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100010
int const mod = 1e9 + 7;
int block;
struct Query{
	int l,r,id,u,v;
	Query(){}
	Query(int a,int b,int c,int d,int e){l = a, r = b, id = c, u = d, v = e; }
	inline pair<int, int> p() const {
		return make_pair(l/block,((l/block)&1)?-r:+r);
	}
};
inline bool operator<(const Query &a, const Query &b) {
	return a.p() < b.p();
}
int n,q;
Query qry[N];
ll mp[10*N];
ll curans = 1;
int lcaqry[N];
ll ansqry[N];
int et[2*N];
int in[N], out[N], temp = 0;
vector<int> adj[N];
int ar[N];
int st[N][20];
int dmax = 0;
int dep[N];
int fac[10*N];
int freq[N];
ll inv[22*N];
vector<pair<int,int>> prim[N];
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)% m;
        a = ( a * a )% m;
        b >>= 1;
    }
    return res;
}
ll invmod(ll x){
	return expmod(x,mod-2,mod);
}
void dfs(int u, int p,int h){
	st[u][0] = (p==-1? 0 : p);
	dep[u] = h;
	dmax = max(dmax,h);
	et[temp] = u;
	in[u] = temp++;
	for(auto v : adj[u]){
		if(v==p) continue;
		dfs(v,u,h+1);
	}
	et[temp] = u;
	out[u] = temp++;
}
void buildlca(){
  for(int j = 1 ; (1<<j) <= dmax ; j++){
    for(int i = 0 ; i < n  ; i++){
      st[i][j] = st[st[i][j-1]][j-1];
    }
  }
}
int getlca(int u,int v){
  if(dep[u] < dep[v]) swap(u,v);
  int bit = 31 - __builtin_clz(dep[u]);
  for(int i = bit ; i >= 0 ; i--){
    if(dep[st[u][i]] >= dep[v]) u = st[u][i];
  }
  bit = 31 - __builtin_clz(dep[u]);
  for(int i = bit ; i >= 0 ; i--){
    if(st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
  }
  if(u==v) return u;
  return st[u][0];
}
void criba(){
  memset(fac,-1,sizeof fac);
  for(ll i = 2 ; i <= 10*N ; i++){
    if(fac[i]==-1){
    	fac[i] = i;
	    for(ll j = i*i ; j <= 10*N ; j+=i){
	      if(fac[j]==-1) fac[j] = i;
	    }
    }
  }
}
void initinv(){
	for(int i = 1 ; i < 22*N ; i++){
		inv[i] = invmod(i);
	}
}
void initprim(){
	int cnt,factor,cur;
	for(int i = 0 ; i < n ; i++){
		cur = ar[i];
		while(fac[cur] != -1){
			cnt = 0, factor = fac[cur];
	    	while(factor == fac[cur]){
	    		cnt++;
	    		cur /= fac[cur];
	    	}
	    	prim[i].pb({factor,cnt});
		}
	}
}
void remov(int x){
	int cnt, factor;
	ll freqfac;
	for(auto v : prim[et[x]]){
		factor = v.first, cnt = v.second;
		freqfac = mp[factor];
		curans = (curans * inv[freqfac+1])%mod;
    	curans = (curans * ((freqfac-cnt+1)%mod+mod)%mod)%mod;
    	mp[factor] -= cnt;
	}
}
void add(int x){
	int cnt, factor;
	ll freqfac;
	for(auto v : prim[et[x]]){
		factor = v.first, cnt = v.second;
		freqfac = mp[factor];
		curans = (curans * inv[freqfac+1])%mod;
    	curans = (curans * (freqfac+cnt+1)%mod)%mod;
    	mp[factor] += cnt;
	}
}
void addc(int x){
	if(freq[et[x]]==0){
		add(x);
	}else{
		remov(x);
	}
	freq[et[x]]++;
}
void removc(int x){
	if(freq[et[x]]==2){
		add(x);
	}else{
		remov(x);
	}
	freq[et[x]]--;
}
ll getans(int id){
	ll ret = curans;
	int cnt, factor;
	ll freqfac;
	for(auto v : prim[lcaqry[id]]){
		factor = v.first, cnt = v.second;
		freqfac = mp[factor];
		ret = (ret * inv[freqfac+1])%mod;
    	ret = (ret * (cnt+freqfac+1)%mod)%mod;
	}
	return ret;
}
void Mos(){
    sort(qry, qry+q);
    int cur_l = 0, cur_r = -1;
    for(int i = 0 ; i < q ; i++){
        while (cur_l > qry[i].l){
            cur_l--;
            addc(cur_l);
        }
        while (cur_r < qry[i].r){
            cur_r++;
            addc(cur_r);
        }
        while (cur_l < qry[i].l){
            removc(cur_l);
            cur_l++;
        }
        while (cur_r > qry[i].r){
            removc(cur_r);
            cur_r--;
        }
        ansqry[qry[i].id] = getans(qry[i].id);
    }
    for(int i = cur_l ; i <= cur_r ; i++){
    	removc(i);
    }
}
int main(){
	FIO;
	criba();
	initinv();
	int t; cin >> t;
	while(t--){
	    cin >> n;
	    block = (int)sqrt(2*n);
	    int u,v;
	    for(int i = 0 ; i < n-1 ; i++){
	      cin >> u >> v;
	      u--,v--;
	      adj[u].pb(v);
	      adj[v].pb(u);
	    }
	    dfs(0,-1,1);
	    buildlca();
	    for(int i = 0; i < n ; i++) cin >> ar[i];
	    initprim();
	    cin >> q;
	    for(int i = 0 ; i < q ; i++){
	    	cin >> u >> v; u--,v--;
	    	if(out[u] > out[v]) swap(u,v); 
	    	qry[i] = Query(out[u],out[v]-1,i,u,v);
	    	lcaqry[i] = getlca(u,v);
	    }
	    Mos();
	    for(int i = 0; i < q ; i++){
	    	cout << ansqry[i] << endl;
	    }
	    temp = 0;
	    curans = 1;
	    for(int i = 0 ; i < n ; i++){
	    	adj[i].clear();
	    	freq[i] = 0;
	    	prim[i].clear();
	    }
	}
	return 0;
}