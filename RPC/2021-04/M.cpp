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
bool dp[2][100005];
int inf = 9999999;
vi v;
int n, c;
vl suma;
int main(){
    cin >> n >> c;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    suma.pb(0);
    for(int i = 0; i < n; i++) {
        int x = v[i] + suma[i];
        if(x > c) suma.pb(inf);
        else suma.pb(x);
    }
    dp[(n) % 2][0] = 1;
    int maxitotal = suma[n];
    for(int i = n - 1; i >= 0; i--) {
        int maxi = -1;
        int ii = i % 2;
        int xs = suma[i];
       // cout << xs << "\n";
       // cout << c - xs - v[i] << " " << c - xs << "\n";
        for(int j = 0; j <= c; j++) {
            dp[ii][j] = dp[1 - ii][j];
            if(j >= v[i]) dp[ii][j] |= dp[1 - ii][j - v[i]];
            if(j > c - xs - v[i] && j <= c - xs && dp[ii][j]) {
                if(maxi == -1) maxi = j;
            }

        }
        if(maxi == -1 || xs == inf) continue;
        //cout << "uwu " << maxi << "\n";
        maxitotal = min(maxi + xs, maxitotal);
    }
    cout << maxitotal << "\n";
    return 0;
}