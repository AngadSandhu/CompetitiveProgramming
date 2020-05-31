#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 515
int n,f,k;
int ar[N][N];
int lasta[N],lastb[N],lastc[N], lastd[N];
bool rowdone[N], coldone[N];
int main(){
	FIO;
    cin >> n >> f;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> ar[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++) lasta[i] = lastc[i] = 0, lastb[i] = lastd[i] = n-1;
    vector<pair<char,int>> ans;
    cin >> k;
    while(k--){
        int a=0,b=0,c=0,d=0;
        int ai, bi, ci, di;
        for(int i = 0 ; i < n ; i++){
            if(rowdone[i]) continue;
            int cant = 0, sum = 0, x = 0;
            for(int j = lasta[i] ; j <= lastb[i] ; j++){
                if(ar[i][j] > 0) sum += ar[i][j], x++;
                if(sum > f){
                    cant = x-1;
                    break;
                }
            }
            if(sum <= f) cant = x;
            if(a < cant) a = cant, ai = i;
            if(x==0) rowdone[i] = 1;
        }
        for(int i = 0 ; i < n ; i++){
            if(rowdone[i]) continue;
            int cant = 0, sum = 0, x = 0;
            for(int j = lastb[i] ; j >= lasta[i] ; j--){
                if(ar[i][j]> 0) sum += ar[i][j], x++;
                if(sum > f){
                    cant = x-1;
                    break;
                }
            }
            if(sum <= f) cant = x;
            if(b < cant) b = cant, bi = i;
            if(x==0) rowdone[i] = 1;
        }
        for(int i = 0 ; i < n ; i++){
            if(coldone[i]) continue;
            int cant = 0, sum = 0, x = 0;
            for(int j = lastc[i] ; j <= lastd[i] ; j++){
                if(ar[j][i] > 0) sum += ar[j][i], x++;
                if(sum > f){
                    cant = x-1;
                    break;
                }
            }
            if(sum <= f) cant = x;
            if(c < cant) c = cant, ci = i;
            if(x==0) coldone[i] = 1;
        }
        for(int i = 0 ; i < n ; i++){
            if(coldone[i]) continue;
            int cant = 0, sum = 0, x = 0;
            for(int j = lastd[i] ; j >= lastc[i] ; j--){
                if(ar[j][i] > 0) sum += ar[j][i], x++;
                if(sum > f){
                    cant = x-1;
                    break;
                }
            }
            if(sum <= f) cant = x;
            if(d < cant) d = cant, di = i;
            if(x==0) coldone[i] = 1;
        }
        int mx = max(max(a,b),max(c,d));
        if(mx==0) break;
        if(mx == a){
            ans.pb({'L',ai+1});
            for(int i = lasta[ai] ; i <= lastb[ai] ; i++){
                if(ar[ai][i]> 0) ar[ai][i] = 0, a--;
                if(!a){
                    lasta[ai] = i+1;
                    break;
                }
            }
        }
        if(lasta[ai]<lastb[ai] && mx==b){
            ans.pb({'R',bi+1});
            for(int i = lastb[bi] ; i >= lasta[bi] ; i--){
                if(ar[bi][i] > 0) ar[bi][i] = 0, b--;
                if(!b){
                    lastb[bi] = i-1;
                    break;
                }
            }
        }
        if(mx==c){
            ans.pb({'U',ci+1});
            for(int i = lastc[ci] ; i <= lastd[ci] ; i++){
                if(ar[i][ci]> 0) ar[i][ci] = 0, c--;
                if(!c){
                    lastc[ci] = i+1;
                    break;
                }
            }
        }
        if(lastc[bi]<lastd[bi] && mx==d){
            ans.pb({'D',di+1});
            for(int i = lastd[di] ; i >= lastc[di] ; i--){
                if(ar[i][di] > 0) ar[i][di] = 0, d--;
                if(!d){
                    lastd[di] = i-1;
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto v : ans) cout << v.first << " " << v.second << endl;
	return 0;
}