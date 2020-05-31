#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
const int mod = 1e9 + 7;
ll C[N][N], f[N][N],fac[N];
void init(){
    fac[0] = 1;
    for(int i = 1 ; i < N ; i++) fac[i] = (i * fac[i-1])%mod;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j==0 || j==i) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i==0) f[i][j] = fac[j];
            else if(j==0) f[i][j] = (i-1)*(f[i-2][j] + f[i-1][j])%mod;
            else f[i][j] = ((i-1)*(f[i-2][j] + f[i-1][j])%mod + j*f[i-1][j]%mod)%mod;
        }
    }
}
int main(){
	FIO;
    init();
    int t; cin >> t;
    int caso = 0;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        cout << "Case " << ++caso << ": " << (C[m][k]*f[m-k][n-m])%mod<< endl;
    }
	return 0;
}