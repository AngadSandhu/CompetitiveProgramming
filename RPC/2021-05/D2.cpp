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
const int N = 200005;
vi adj[N];
vl capa;
vi canti;
ll mini = LLONG_MAX;
void dfs(int u, int parent, ll activ) {
    
    ll nactiv = max(capa[u], activ) -  canti[u];
    if(capa[u] >= activ) mini = min(mini, nactiv);
    for(auto v : adj[u]) {
        if(parent == v) continue;
        dfs(v, u, nactiv);
    }
}
int main(){
    int n, w;
    cin >> n >> w;
    int root;
    capa.pb(w);
    canti.pb(0);
    for(int i = 1, p; i <= n; i++) {
        cin >> p;
        int cc, ww;
        cin >> cc >> ww;
        capa.pb(cc);
        canti.pb(ww);
        adj[i].pb(p);
        adj[p].pb(i);
    }    
    dfs(0, 0, 0);
    cout << mini << "\n";
    return 0;
}