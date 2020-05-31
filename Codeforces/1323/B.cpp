#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 40005
ll n,m,k;
ll a[N],b[N];
ll p1[N], p2[N];
int main(){
	FIO;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    a[n] = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    b[m] = 0;
    int cur = 0;
    for(int i = 0 ; i <= n ; i++){
        if(a[i]==1) cur++;
        else{
            for(int j = 1 ; j <= cur ; j++){
                p1[j] += cur-j+1;
            }
            cur = 0;
        }
    }
    cur = 0;
    for(int i = 0 ; i <= m ; i++){
        if(b[i]==1) cur++;
        else{
            for(int j = 1 ; j <= cur ; j++){
                p2[j] += cur-j+1;
            }
            cur = 0;
        }
    }
    ll res = 0;
    for(ll i = 1 ; i*i <= k ; i++){
        if(k%i==0){
            if(i > N || k/i > N) continue;
            res += p1[i]*p2[k/i];
            if(i!=k/i) res += p1[k/i]*p2[i];
        }
    }
    cout << res << endl;
	return 0;
}