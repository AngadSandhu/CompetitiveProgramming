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
const int MOD = 998244353;
string s1, s2;
int n1, n2;
int dp[100005][2][2][11];
int dpp(int pos, int menor, int mayor, int last) {
    if(pos == n2) return 1;
    if(dp[pos][menor][mayor][last] != -1) return dp[pos][menor][mayor][last];
    int ans = 0;
    int li = 0;
    int ls = 9;
    if(!menor) ls = s2[pos] - '0';
    if(!mayor) li = s1[pos] - '0'; 
    for(int i = li; i <= ls; i++) {
        int nmenor = menor, nmayor = mayor;
        if(i != li) nmayor = 1;
        if(i != ls) nmenor = 1;
        if(i == 0 && last == 10) {
            ans = ans + dpp(pos + 1, nmenor, nmayor, 10);
            continue;
        }
        if(i == last) continue;
        ans = (ans + dpp(pos + 1, nmenor, nmayor, i)) % MOD;
    }
    return dp[pos][menor][mayor][last] = ans;


}
int main(){
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    n1 = s1.size();
    n2 = s2.size(); 
    for(int i = 0; i < n2 - n1; i++) {
        s1 = '0' + s1;
    }
    cout << dpp(0, 0, 0, 10) << "\n";
    return 0;
}