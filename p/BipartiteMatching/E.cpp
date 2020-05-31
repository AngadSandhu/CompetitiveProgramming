#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 305
#define eps 1e-6
int pl[N], pr[N];
int n,m,s,v;
pair<double,double> L[N], R[N];
vector<int> adj[N];
bool visit[N];
bool check(double x,double y,double d){
    return (x*x + y*y) <= d*d + eps;
}
bool dfs(int u){
    if(visit[u]) return false;
    visit[u] = 1;
    for(auto v : adj[u]){
        if(pr[v] == -1 || dfs(pr[v])){
            pl[u] = v;
            pr[v] = u;
            return true;
        }
    }
    return false;
}
bool ford(){
    memset(visit,0,sizeof visit);
    for(int i = 0 ; i < n ; i++){
        if(pl[i] == -1 && dfs(i)) return true;
    }
    return false;
}
int main(){
	FIO;
    while(cin >> n >> m >> s >> v){
        for(int i = 0 ; i < n ; i++){
            cin >> L[i].first >> L[i].second;
        }
        for(int i = 0 ; i < m ; i++){
            cin >> R[i].first >> R[i].second;
        }
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(check(L[i].first-R[j].first,L[i].second-R[j].second,v*s*1.0)){
                    adj[i].pb(j);
                }
            }
        }
        memset(pl,-1,sizeof pl);
        memset(pr,-1,sizeof pr);
        while(ford());
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(pl[i]==-1) ans++;
        }
        cout << ans << endl;
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }	
	return 0;
}