#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
struct point{
    ll x,y,t;
    ld p;
    point(){};
    point(int x,int y,int t,ld p): x(x), y(y), t(t), p(p) {};
};
bool valid(point &p1, point &p2){
    return (p2.t-p1.t)*(p2.t-p1.t) >= (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int n;
point a[N];
vector<int> adj[N];
ld dp[N];
ld dfs(int u){
    if(dp[u] > -0.5) return dp[u];
    ld ret = 0;
    for(auto v : adj[u]){
        ret = max(ret,dfs(v));
    }
    return dp[u] = ret + a[u].p;
}
int main(){
	FIO;
    cin >> n;
    fill(dp,dp+n,-1);
    for(int i = 0 ; i < n ; i++) cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[i].t < a[j].t && valid(a[i],a[j])) adj[i].pb(j);
        }
    }
    ld ans = 0;
    for(int i = 0 ; i < n ; i++) ans = max(ans, dfs(i));
    cout << fixed << setprecision(6) << ans << endl;
	return 0;
}