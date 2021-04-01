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
 	int n, p;
 	cin >> n >> p;
 	vi v(n), v2;
 	for(int i = 0; i < n; i++) cin >> v[i];
 	reverse(all(v));
 	int cnt = 0;
 	int problems = 0;
 	for(int i = 0; i < n; i++) {
 		if(v[i] <= cnt) {
 			cnt = v[i];
 		}
 		else {
 			cnt = v[i];
 			problems++;
 		}
 		v2.pb(problems);
 	}
 	if(v2.back() != p && v2.back() != 0) {
 		cout << "ambiguous\n";
 	}
 	else {
 		reverse(all(v2));
 		for(auto e : v2) cout << e << "\n";
 	}
 	
	return 0;
}