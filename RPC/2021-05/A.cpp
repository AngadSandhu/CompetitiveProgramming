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
const int N = 100005;
vi adj[N];
multiset<ll>s[N];
void dfs(int u, int parent) {
    if(adj[u].size() == 1) {
        s[u].insert(-1);
        return;
    }
    for(auto v : adj[u]) {
        if(v == parent)continue;
        dfs(v, u);
        if(s[u].size() < s[v].size()) swap(s[u], s[v]);
        for(auto e : s[v]) s[u].insert(e);
    }
    int it = *s[u].begin();
    s[u].erase(s[u].begin());
    s[u].insert(it - 1);
}
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi v(k);
    for(int i = 0; i < k; i++) {
        cin >> v[i];
    }
    for(int i = 1, x; i < n; i++) {
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs(0, 0);
    int id = 0;
    ll ans = 0;
    sort(all(v));
    reverse(all(v));
    for(auto e : s[0]) {
        ans -= 1LL * v[id] * e; 
        id++;
    }
    ans -= v[0];
    cout << "\n";
    cout << ans << "\n";
    return 0;
}