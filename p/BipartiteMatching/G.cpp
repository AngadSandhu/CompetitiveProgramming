#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 505
int pl[N], pr[N];
int n,m;
bool adj[N][N];
bool visit[N];
bool aug(int u){
    if(visit[u]) return false;
    visit[u] = 1;
    for(int v = 0 ; v < m ; v++){
        if(adj[u][v]==0) continue;
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
            for(int j = 0 ; j < m ; j++){
                if(adj[i][j]==0) continue;
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
	int t, caso = 0;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> adj[i][j];
            }
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++caso,match());
    }
	return 0;
}