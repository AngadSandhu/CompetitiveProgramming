const int block = 400;
struct Query{
	int l,r,id,u,v;
	Query(){};
	Query(int a,int b,int c,int d,int e): l(a), r(b), id(c), u(d), v(e) {};
	inline pair<int, int> p() const{ return make_pair(l/block,((l/block)&1)?-r:+r); }
};
inline bool operator<(const Query &a, const Query &b){ return a.p() < b.p(); }
Query qry[N];
void Mos(){
    sort(qry, qry+q); // sort according to query sort
    int l = 0, r = -1;
    for(int i = 0 ; i < q ; i++){
        while (l > qry[i].l) add(--l);
        while (r < qry[i].r) add(++r);
        while (l < qry[i].l) remov(l++);
        while (r > qry[i].r) remov(r--);
        ansqry[qry[i].id] = getans(qry[i].id);
    }
}
