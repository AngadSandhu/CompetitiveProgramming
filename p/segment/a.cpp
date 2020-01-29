#include<bits/stdc++.h>
#define N 100005
#define LS 2*node
#define RS 2*node+1
typedef long long ll;
using namespace std;
struct data{
	int sum,pref,suf,ans;
	data(){}
	data(int a,int c,int d,int e){sum = a; pref = c; suf = d; ans = e;}
};
data tree[4*N];
int ar[N];
int n;
data merge(const data &d1,const data &d2){
	data ret(0,0,0,0);
	ret.sum = d1.sum + d2.sum;
	int ran = max(max(d1.suf,d2.pref),d1.suf + d2.pref);
	ret.suf = max(d2.suf,d2.sum + d1.suf);
	ret.pref = max(d1.pref,d1.sum+d2.pref);
	ret.ans = max(max(max(ret.suf,ran),ret.pref),max(d1.ans,d2.ans));
	return ret;
}
void update(int node,int l,int r,int pos,int val){
	if(l>pos || r<pos) return;
	if(l==r && l==pos){
		ar[pos] = val;
		tree[node] = data(val,val,val,val);
		return;
	}
	int med = (l+r)/2;
	update(LS,l,med,pos,val);
	update(RS,med+1,r,pos,val);
	tree[node] = merge(tree[LS],tree[RS]);
}
data query(int node,int l,int r,int lq,int rq){
	if(l>=lq && r<=rq) return tree[node];
	int med = (l+r)/2;
	data ret(0,0,0,0);
	if(med<lq){
		ret = query(RS,med+1,r,lq,rq);
		return ret;
	}
	if(med+1>rq){
		ret = query(LS,l,med,lq,rq);
		return ret;
	}
	data r1 = query(LS,l,med,lq,rq);
	data r2 = query(RS,med+1,r,lq,rq);
	ret = merge(r1,r2);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
		update(1,0,n-1,i,ar[i]);
	}
	int q,x,y;
	cin >> q;
	while(q--){
		cin >> x >> y;
		cout << query(1,0,n-1,x-1,y-1).ans << endl;
	}
	return 0;
}
