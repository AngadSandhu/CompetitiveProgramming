#include<bits/stdc++.h>
#define N 100005
#define LS 2*node
#define RS 2*node+1
typedef long long ll;
using namespace std;
struct data{
	int mx,mxsum;
	data(){}
	data(int a,int b){ mx = a; mxsum = b; }
};
data tree[4*N];
int ar[N];
int n;
data merge(data d1,data d2){
	data ret(0,0);
	ret.mx = max(d1.mx,d2.mx);
	ret.mxsum = max(d1.mx+d2.mx,max(d1.mxsum,d2.mxsum));
	return ret;
}
void update(int node,int l,int r,int pos,int val){
	if(l>pos || r<pos) return;
	if(l==r && l==pos){
		ar[pos] = val;
		tree[node].mx = val;
		tree[node].mxsum = 0;
		return;
	}
	int med = (l+r)/2;
	update(LS,l,med,pos,val);
	update(RS,med+1,r,pos,val);
	tree[node] = merge(tree[LS],tree[RS]);
}
data query(int node,int l,int r,int lq,int rq){
	if(l>rq || r<lq) return data(0,0);
	if(l>=lq && r<=rq) return tree[node];
	int med = (l+r)/2;
	data r1 = query(LS,l,med,lq,rq);
	data r2 = query(RS,med+1,r,lq,rq);
	return merge(r1,r2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
		update(1,0,n-1,i,ar[i]);
	}
	char op;
	int q,x,y;
	cin >> q;
	while(q--){
		cin >> op >> x >> y;
		if(op=='U'){
			update(1,0,n-1,x-1,y);
		}
		if(op=='Q'){
			cout << query(1,0,n-1,x-1,y-1).mxsum << endl;
		}
	}
	return 0;
}
