#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
long double memo[N][N][2];
long double dp(int w,int b,bool i){
    if(w <= 0) return 0;
    if(b <= 0) return i;
    long double &ret = memo[w][b][i];
    if(ret > -0.5) return ret;
    if(i==1){
        return ret = (1.0*w/(w+b)) + (1.0*b/(w+b))*dp(w,b-1,0);
    }else{
        return ret = (1.0*b/(w+b))*((1.0*w/(w+b-1))*dp(w-1,b-1,1) + (1.0*(b-1)/(w+b-1))*dp(w,b-2,1));
    }
}
int main(){
	FIO;
	int n,m; cin >> n >> m;
    for(int i = 0 ; i <= n ; i++) for(int j = 0 ; j <= m ; j++) memo[i][j][0] = memo[i][j][1] = -1;
    cout << fixed << setprecision(9) << dp(n,m,1) << endl;
	return 0;
}