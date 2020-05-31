#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 2005
long double memo[N][N];
int n,s;
long double p;
long double dp(int i,int t){
    if(i-1 == n) return n;
    if(t==0) return i-1;
    if(memo[i][t] > -0.5) return memo[i][t];
    return memo[i][t] = p*dp(i+1,t-1) + (1-p)*dp(i,t-1);
}
int main(){
	FIO;
    cin >> n >> p >> s;
	for(int i = 0; i <= n ; i++){
        for(int j = 0 ; j <= s ; j++){
            memo[i][j] = -1;
        }
    }
    cout << fixed << setprecision(7) << dp(1,s) << endl;
	return 0;
}