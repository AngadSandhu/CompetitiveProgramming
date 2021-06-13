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
    for(int i = 0, x; i < n; i++) {
        cin >> v[i];
    }

    int mini = 1000000000;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int cur = 0;
            for(int k = 0; k < n; k++) {
                cur += min((v[i] - v[k]) * (v[i] - v[k]), (v[j] - v[k]) * (v[j] - v[k]));
            }
            mini = min(mini, cur);
        }
    }
    cout << mini << "\n";
    return 0;
}