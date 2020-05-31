#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 36
int n;
int ar[N];
ll C[N][N];
ll fc(int n, int k){
    if(C[n][k] != -1) return C[n][k];
    if(k == 0 || k == n) return C[n][k] = 1;
    return C[n][k] = fc(n-1,k-1) +  fc(n-1,k);
}
ll back(int pos,ll sum,int k, int first){
    if(k==0) return (sum > 2*first);
    if(pos < k) return 0;
    if(first != -1 && sum > 2*first) return C[pos][k];
    if(first == -1){
        return back(pos-1,sum+ar[pos],k-1,ar[pos]) + back(pos-1,sum,k,first);
    }else{
        return back(pos-1,sum+ar[pos],k-1,first) + back(pos-1,sum,k,first);
    }
}
int main(){
	FIO;
    memset(C,-1,sizeof C);
    for(int i = 1 ; i <= 30 ; i++){
        for(int j = 1; j <= i ; j++){
            fc(i,j);
        }
    }
    int t, caso = 0; cin >> t;
    while(t--){
        int K;
        cin >> n >> K;
        for(int i = 1 ; i <= n ; i++) cin >> ar[i];
        sort(ar+1,ar+n+1);
        cout << "Case " << ++caso << ": " << back(n,0,K,-1) << endl;
    }
	return 0;
}
