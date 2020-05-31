#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
ll dp1[61][N],dp2[61][N];
int main(){
	FIO;
    int n; cin >> n;
    vector<int> a(n); for(int &i:a) cin >> i;
    for(int i = -30 ; i <= 30 ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(a[j-1] <= i) dp1[i+30][j] = max(0ll,a[j-1] + max(0ll,dp1[i+30][j-1]));
            else dp1[i+30][j] = 0;
        }
    }
    for(int i = -30 ; i <= 30 ; i++){
        for(int j = n ; j > 0 ; j--){
            if(a[j-1] <= i) dp2[i+30][j] = max(0ll,a[j-1] + max(0ll,dp2[i+30][j+1]));
            else dp2[i+30][j] = 0;
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans, dp1[a[i]+30][i] + dp2[a[i]+30][i+2]);
    }
    cout << ans << endl;
	return 0;
}