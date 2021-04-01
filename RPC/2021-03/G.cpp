#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
struct edge{
	int u, v;
	ll w;
	edge(){}
	edge(int _u, int _v, ll _w) {
		u = _u, v = _v, w = _w;
	}
};
int uf[100005];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}
void join(int a, int b) {
	a = find(a), b = find(b);
	if(uf[a] > uf[b]) {
		swap(a, b);
	}
	uf[a] += uf[b];
	uf[b] = a;
}
vector<edge> edges;

int main(){
	memset(uf, -1, sizeof(uf));
 	int n, m;
 	cin >> n >> m;
 	for(int i = 0; i < m; i++) {
 		int c, a;
 		cin >> c >> a;
 		edges.pb(edge(0, c, a));
 	}
 	int x;
 	for(int i = 1; i < n; i++) {
 		cin >> x;
 		edges.pb(edge(i, i + 1, x));
 	}
	cin >> x;
	edges.pb(edge(1, n, x));
	sort(all(edges), cmp);
	n++;
	ll total = 0;
	for(auto e : edges) {
		if(find(e.u) != find(e.v)) {
			join(e.u, e.v);
			total += e.w;
		}
	}
	cout << total << "\n";
	return 0;
}