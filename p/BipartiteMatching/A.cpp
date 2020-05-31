#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int pl[N], pr[N];
int n;
int l[N],r[N],u[N],d[N];
int px[N],py[N];
bool adj[N][N];
bool visit[N];
bool inside(int i,int j){
    return ((l[i] < px[j] && r[i] > px[j]) && (d[i] < py[j] && u[i] > py[j]));
}
bool aug(int u){
    if(visit[u]) return false;
    visit[u] = 1;
    for(int v = 0 ; v < n ; v++){
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
    fill(pr,pr+n,-1);
    //Greedy init
    for(int i = 0 ; i < n ; i++){
        if(pl[i]==-1){
            for(int j = 0 ; j < n ; j++){
                if(adj[i][j] == 0) continue;
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
int maxmatch(){
    kuhn();
    int ret = 0;
    for(int i = 0 ; i < n ; i++) ret += (pl[i]!=-1);
    return ret;
}
int main(){
	FIO;
    int caso = 0;
	while(cin >> n, n > 0){
        for(int i = 0 ; i < n ; i++){
            cin >> l[i] >> r[i] >> d[i] >> u[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin >> px[i] >> py[i];
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(inside(i,j)) adj[i][j] = 1;
            }
        }
        int mx = maxmatch();
        vector<pair<char,int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(adj[i][j]==0) continue;
                adj[i][j] = 0;
                if(maxmatch() != mx) ans.pb({char(i+'A'),j+1});
                adj[i][j] = 1;
            }
        }
        cout << "Heap " << ++caso << endl;
        if(ans.size()==0) cout << "none" << endl;
        else{
            for(int i = 0 ; i < (int)ans.size() ; i++){
                if(i) cout << " ";
                cout << "(" << ans[i].first << "," << ans[i].second << ")"; 
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                adj[i][j] = 0;
            }
        }
    }
	return 0;
}