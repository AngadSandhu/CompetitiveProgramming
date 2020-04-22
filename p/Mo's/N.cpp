#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
const int block = 400;
struct Query{
	int l,r,id;
	Query(){};
	Query(int a,int b,int c): l(a), r(b), id(c) {};
	inline pair<int, int> p() const{ return make_pair(l/block,((l/block)&1)?-r:+r); }
};
inline bool operator<(const Query &a, const Query &b){ return a.p() < b.p(); }
int n,q,k;
Query qry[N];
int ar[N], arx[N];
ll ansqry[N], freq[50*N], cur = 0;
void add(int x){
    cur += freq[ar[x]^k];
    freq[ar[x]]++;
}
void remov(int x){
    freq[ar[x]]--;
    cur -= freq[ar[x]^k];
}
void solve(){
    sort(qry,qry+q);
    int l = 0, r = -1;
    for(int i = 0 ; i < q ; i++){
        while (l > qry[i].l) add(--l);
        while (r < qry[i].r) add(++r);
        while (l < qry[i].l) remov(l++);
        while (r > qry[i].r) remov(r--);
        ansqry[qry[i].id] = cur;
    }
}
int main(){
	FIO;
    cin >> n >> q >> k;
    for(int i = 1 ; i <= n ; i++) cin >> ar[i];
    ar[0] = 0;
    for(int i = 1 ; i <= n ; i++) ar[i] ^= ar[i-1];
    for(int i = 0 ; i < q ; i++) cin >> qry[i].l >> qry[i].r, qry[i].l--, qry[i].id = i;
    solve();
    for(int i = 0 ; i < q ; i++) cout << ansqry[i] << endl;
	return 0;
}