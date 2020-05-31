#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N
ld dp[18][1<<18], p[18][18];
int n;
ld f(int cur,int mask){
    int bits = __builtin_popcount(mask);
    if(bits==1){
        return (mask&1);
    }
    if(dp[cur][mask] > -0.5) return dp[cur][mask];
    ld ret = 0;
    for(int i = 0 ; i < n ; i++){
        if(i==cur) continue;
        if((mask>>i)&1){
            ret = max(ret, p[cur][i]*f(cur,mask^(1<<i)) + p[i][cur]*f(i,mask^(1<<cur)));
        }
    }
    return dp[cur][mask] = ret;
}
int main(){
	FIO;
	cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin >> p[i][j];
        }
    }
    for(int i = 0 ; i < (1<<n) ; i++){
        for(int j = 0 ; j < n ; j++) dp[j][i] = -1;
    }
    ld ans = 0;
    for(int i = 0 ; i < n ; i++) ans = max(ans,f(i,(1<<n)-1));
    cout << fixed << setprecision(6) << ans << endl;
	return 0;
}