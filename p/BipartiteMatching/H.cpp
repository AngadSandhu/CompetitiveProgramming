#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int a[N],b[N];
int pl[N], pr[N];
int n,m;
vector<int> adj[N];
bool visit[N];
bool aug(int u){
    if(visit[u]) return false;
    visit[u] = 1;
    for(auto v : adj[u]){
        if(pr[v] == -1 || aug(pr[v])){
            pl[u] = v;
            pr[v] = u;
            return true;
        }
    }
    return false;
}
void kuhn(){
    fill(pl,pl+n,-1);
    fill(pr,pr+m,-1);
    //Greedy init
    for(int i = 0 ; i < n ; i++){
        if(pl[i]==-1){
            for(auto j : adj[i]){
                if(pr[j]== -1){
                    pl[i] = j;
                    pr[j] = i;
                    break;
                }
            }
        }
    }
    //Algorithm
    for(int i = 0 ; i < n ; i++){
        if(pl[i] == -1){
            fill(visit,visit+n,0);
            aug(i);
        }
    }
}
int match(){
    kuhn();
    int ret = 0;
    for(int i = 0 ; i < n ; i++) ret += (pl[i]!=-1);
    return ret;
}
int main(){
	FIO;
	int t, caso = 0; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> b[i];
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
                if(a[i]==0){
                    if(b[j]==0) adj[i].pb(j);
                    else continue;
                }else if(b[j]%a[i]==0) adj[i].pb(j);
            }
        }
        cout << "Case "<< ++caso << ": " << match() << endl;
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }
	return 0;
}