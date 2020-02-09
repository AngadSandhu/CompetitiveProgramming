#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LS 2*node
#define RS 2*node+1
#define N 400005

struct dat{
	ll mask = 0;
	int flag = 0;
	dat(){}
};
dat tree[8*N];
int in[N],out[N];
int temp = 0;
vector<int> adj[N];
int n,q;
int color[N];
void push(int node,int l,int r){
	if(tree[node].flag==0) return;
	tree[node].mask = (1ll<<(tree[node].flag));
	if(l!=r){
		tree[LS].flag = tree[node].flag;
		tree[RS].flag = tree[node].flag;
	}
	tree[node].flag = 0;
}
void update(int node,int l,int r,int lq,int rq,int val){
	push(node,l,r);
	if(l>rq || r<lq) return;
	if(l>=lq && r<=rq){
		tree[node].flag = val;
		push(node,l,r);
		return;
	}
	int med = (r+l)/2;
	update(LS,l,med,lq,rq,val);
	update(RS,med+1,r,lq,rq,val);
	tree[node].mask = tree[LS].mask | tree[RS].mask;
}
ll query(int node,int l,int r,int lq,int rq){
    push(node,l,r);
	if(l>rq||r<lq) return 0;
	if(l>=lq && r<=rq) return tree[node].mask;
	int med = (r+l)/2;
	return query(LS,l,med,lq,rq)|query(RS,med+1,r,lq,rq);
}
void dfs(int v,int p){
    in[v] = temp++;
    for(auto u : adj[v]){
        if(u!=p)
            dfs(u,v);
    }
    out[v] = temp++;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
    for(int i = 0 ; i < n ; i++) cin >> color[i];
    for(int i = 0 ; i < n-1; i++){
        int u,v; cin >> u >>  v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    for(int i = 0 ; i < n ; i++){
        update(1,0,2*n-1,in[i],in[i],color[i]);
        update(1,0,2*n-1,out[i],out[i],color[i]);
    }
    for(int i = 0 ; i < q ; i++){
        int caso;
        cin >> caso;
        if(caso==1){
            int v,c; cin >> v >> c; v--;
            update(1,0,2*n-1,in[v],out[v],c);
        }else{
            int v; cin >> v; v--;
            cout << __builtin_popcountll(query(1,0,2*n-1,in[v],out[v])) << endl;
        }
    }
	return 0;
}