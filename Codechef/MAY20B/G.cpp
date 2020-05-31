#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
ll ar[N][N], p[N][N], r[N], c[N];
int id[N][N], ans[N];
ll n,m,q;
ll dp[N][2][2];
int recon[N][2][2];
ll f(int pos,bool ant1, bool ant2){
    if(pos==m) return 0;
    if(dp[pos][ant1][ant2] != -1) return dp[pos][ant1][ant2];
    ll ret = 0;
    for(int i = 0 ; i < (1<<2) ; i++){
        ll cur = 0;
        int sg1 = (i==1||i==3)?1:-1, sg2 = (i==2||i==3)?1:-1;
        cur += sg1 * p[0][pos] * ar[0][pos]; //Esta
        if(pos>0) cur += sg1 * p[0][pos] * ((ant1?1:-1)*p[0][pos-1]); //ANT
        cur += sg2 * p[1][pos] * ar[1][pos]; //Esta
        if(pos>0) cur += sg2 * p[1][pos] * ((ant2?1:-1)*p[1][pos-1]); //ANT
        cur += sg1*sg2 * p[0][pos] * p[1][pos]; //Los dos
        cur += f(pos+1,i&(1<<0),i&(1<<1));
        if(ret < cur){
            ret = cur;
            recon[pos][ant1][ant2] = i;
        }
    }
    return dp[pos][ant1][ant2] = ret;
}
void construct(int pos,bool ant1, bool ant2){
    if(pos==m) return;
    int mask = recon[pos][ant1][ant2];
    if(id[0][pos]!=-1) ans[id[0][pos]] = (mask==1||mask==3)?1:-1;
    if(id[1][pos]!=-1) ans[id[1][pos]] = (mask==2||mask==3)?1:-1;
    construct(pos+1,mask&(1<<0),mask&(1<<1));
}
int main(){
	FIO;
    memset(dp,-1,sizeof dp);
    memset(id,-1,sizeof id);
	int t; cin >> t;
    while(t--){
        cin >> n >> m >> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> ar[i][j];
            }
        }
        for(int i = 0 ; i < q ; i++){
            cin >> r[i] >> c[i];
            cin >> p[--r[i]][--c[i]];
            id[r[i]][c[i]] = i;
        }
        if(n <= 2){
            cout << f(0,0,0) << endl;
            construct(0,0,0);
            for(int i = 0 ; i < q ; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }else{
            ll res = 0, mask;
            for(ll i = 0 ; i < (1ll<<q) ; i++){
                ll ret = 0;
                for(int j = 0 ; j < q ; j++){
                    if(i&(1ll<<j)) p[r[j]][c[j]] = abs(p[r[j]][c[j]]);
                    else p[r[j]][c[j]] = -abs(p[r[j]][c[j]]);
                    ret += p[r[j]][c[j]]*ar[r[j]][c[j]];
                }
                for(int j = 0 ; j < q ; j++){
                    for(int k = j+1 ; k < q ; k++){
                        if((r[j]==r[k] && abs(c[j]-c[k])==1) || (c[j]==c[k] && abs(r[j]-r[k])==1)) ret += p[r[j]][c[j]]*p[r[k]][c[k]];
                    }
                }
                if(res < ret) res = ret, mask = i;
            }
            cout << res << endl;
            for(int i = 0 ; i < q ; i++){
                cout << (mask&(1ll<<i) ? "1" : "-1") << " ";
            }
            cout << endl;
        }
        for(int i = 0 ; i < n+2 ; i++){
            for(int j = 0 ; j < m+2 ; j++){
                ar[i][j] = p[i][j] = 0;
                id[i][j] = -1;
            }
        }
        for(int i = 0 ; i < m+2 ; i++) memset(dp[i],-1,sizeof dp[i]);
    }
	return 0;
}