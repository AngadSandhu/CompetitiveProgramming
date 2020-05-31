#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 18
ld dp[1<<18][18];
ld p[N][N];
int n;
int main(){
	FIO;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) cin >> p[i][j];
	}
	for(int i = 0  ; i < (1<<n) ; i++){
		for(int j = 0 ; j < n ; j++){
			if(((i>>j)&1) == 0) dp[i][j] = 0;
			else if(__builtin_popcount(i)==1) dp[i][j] = 1;
		}
	}
	for(int i = 0 ; i < (1<<n) ; i++){
		vector<int> v;
		for(int j = 0 ; j < n ; j++) if((i>>j)&1) v.pb(j);
		int m = v.size();
		for(int f = 0 ; f < m ; f++){
			for(int j = 0 ; j < m ; j++){
				for(int k = 0 ; k < m ; k++){
					if(j==k) continue;
					dp[i][v[f]] += p[v[j]][v[k]]*dp[i^(1<<v[k])][v[f]]/((ld)m*(m-1)/2);
				}
			}
		}	
	}
	cout << fixed << setprecision(6);
	for(int i = 0 ; i < n ; i++) cout << dp[(1<<n)-1][i] << " "; cout << endl;
	return 0;
}