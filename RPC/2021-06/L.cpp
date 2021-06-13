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
    int k;
    cin >> k;
    int cas = 0;
    vi res;
    while(k--) {
        cas++;
        int n;
        cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vi maxi(n);
        maxi[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--) maxi[i] = max(maxi[i + 1], v[i]);
        vi carga;
        carga.pb(v[0]);
        bool flag = 0;
        for(int i = 1; i < n - 1; i++) {
            int id = upper_bound(all(carga), v[i]) - carga.begin();
            if(id != i) {
                if(maxi[i + 1] > carga[id]) {
                    flag = 1;
                    break;
                }
            }
            carga.pb(v[i]);
        }
        if(flag) res.pb(cas);

    }
    int nn = res.size();
    cout << nn << "\n";
    sort(all(res));
    for(auto e : res) cout << e << "\n";
    return 0;
}