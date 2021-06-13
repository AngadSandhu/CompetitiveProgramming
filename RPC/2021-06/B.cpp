#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
int main(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    ll favo = 0;
    for(int i = 0; i < n; i++) {
        favo += 1LL  * (1LL << i) * v[i]; 
    }
    ll total = 1LL << n;
    long double res = favo;
    res = res/total;
    double reso = res;
    printf("%.6f\n", reso); 
    return 0;
}
