#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 5000006
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define RB(x) (x<n?r[x]:0)
int SA[N], iSA[N], lcp[N];
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
void build_sa(string& s){ // sa (0,n-1)
	s += "#";
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	fore(i,1,n) SA[i-1] = sa[i], iSA[sa[i]] = i-1;
	s.erase(s.size()-1);
}
void build_lcp(string const& s){ // lcp[i] = lcp(sa[i-1],sa[i]) , (0,n-1)
    int n = s.size();
    for(int i = 0, k = 0; i < n; i++) {
        if(iSA[i] == n - 1){ k = 0; continue; }
        int j = SA[iSA[i] + 1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[iSA[i]] = k;
        if(k) k--;
    }
    for(int i = n-1 ; i >= 0 ; i--) lcp[i+1] = lcp[i];
    lcp[0] = 0; 
}
int rmq[N][25], go[N], sz[N];
int n,m,q;
void build_rmq(){
	for(int i = 0 ; i < n ; i++) rmq[i][0] = lcp[i];
	for(int j = 1 ; (1<<j) <= n ; j++){
		for(int i = 0 ; i + (1<<j) <= n; i++){
			rmq[i][j] = min(rmq[i+(1<<(j-1))][j-1],rmq[i][j-1]);	
		}
	}
}
int query_rmq(int i,int j){
	int b = 31-__builtin_clz(j-i+1);
	return min(rmq[i][b],rmq[j+1-(1<<b)][b]);
}
int main(){
	FIO;
	int t,caso = 0; cin >> t;
	while(t--){
		cin >> m;
		string s,x;
		fore(i,0,m){
			cin >> x;
			go[i] = s.size();
			sz[i] = x.size();
			s += x + "$";
		}
		s.erase(s.size()-1);
		n = s.size();
		build_sa(s);
		build_lcp(s);
		build_rmq();
		cout << "Case " << ++caso << ":" << endl;
		cin >> q;
		int u,v;
		fore(i,0,q){
			cin >> u >> v;
			u--, v--;
			if(iSA[go[u]]>iSA[go[v]]) swap(u,v);
			if(u!=v) cout << min(sz[u],query_rmq(iSA[go[u]]+1,iSA[go[v]])) << endl;
			else cout << sz[u] << endl;
		}
	}
	return 0;
}