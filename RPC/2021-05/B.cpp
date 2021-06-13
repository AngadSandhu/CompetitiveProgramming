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
ll pot[54];
int main(){
    pot[0] = 1;
    for(int i = 1; i < 53; i++) {
        pot[i] = 2LL * pot[i - 1];
    }
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    ll ans = 0;
    for(int i = 0; i + 2 < n; i++) {
        for(int j = i + 1; j + 1 < n; j++) {
            int id = lower_bound(all(v), v[i] + v[j]) - v.begin();
            id--;
            if(id == j) continue;
            int cnt = id - j;
            ans += pot[cnt] - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}