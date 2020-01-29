#include<bits/stdc++.h>
using namespace std;
#define LS 2*node
#define RS 2*node+1
#define N 100005

struct data{
	int cant[3] = {};
	int flag = 0;
	data(){}
};
data tree[4*N];
int n,q;
void push(int node,int l,int r){
	if(tree[node].flag==0) return;
	int i = tree[node].flag;
	int aux[] = {tree[node].cant[0],tree[node].cant[1],tree[node].cant[2]};
	tree[node].cant[i%3] = aux[0];
	tree[node].cant[(i+1)%3] = aux[1];
	tree[node].cant[(i+2)%3] = aux[2];
	if(l!=r){
		tree[LS].flag++;
		tree[RS].flag++;
	}
	tree[node].flag = 0;
}
void update(int node,int l,int r,int lq,int rq){
	push(node,l,r);
	if(l>rq || r<lq) return;
	if(l>=lq && r<=rq){
		tree[node].flag++;
		push(node,l,r);
		return;
	}
	int med = (r+l)/2;
	update(LS,l,med,lq,rq);
	update(RS,med+1,r,lq,rq);
	tree[node].cant[0] = tree[LS].cant[0] + tree[RS].cant[0];
	tree[node].cant[1] = tree[LS].cant[1] + tree[RS].cant[1];
	tree[node].cant[2] = tree[LS].cant[2] + tree[RS].cant[2];
}
data query(int node,int l,int r,int lq,int rq){
	push(node,l,r);
	if(l>rq||r<lq) return data();
	if(l>=lq && r<=rq) return tree[node];
	int med = (r+l)/2;
	data r1 = query(LS,l,med,lq,rq);
	data r2 = query(RS,med+1,r,lq,rq);
	data ret;
	ret.cant[0] = r1.cant[0] + r2.cant[0];
	ret.cant[1] = r1.cant[1] + r2.cant[1];
	ret.cant[2] = r1.cant[2] + r2.cant[2];
	return ret;
}
void build(int node,int l,int r){
	tree[node].cant[0] = (r-l+1);
	if(l==r) return;
	int med = (r+l)/2;
	build(LS,l,med);
	build(RS,med+1,r);
}
int main(){
	cin >> n >> q;
	build(1,0,n-1);
	bool op;
	int A,B;
	while(q--){
		cin >> op >> A >> B;
		if(op){
			cout << query(1,0,n-1,A,B).cant[0] << endl;
		}else{
			update(1,0,n-1,A,B);
		}
	}
	return 0;
}
