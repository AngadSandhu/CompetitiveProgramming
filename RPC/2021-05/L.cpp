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
    set<int>s;
    int sum = 0;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        sum += x;
        s.insert(x);
    }
    if(sum % 2 == 0 && s.count(sum/2) != 0) {
        cout << sum/2 << "\n";
    }
    else cout << "BAD\n";
    return 0;
}