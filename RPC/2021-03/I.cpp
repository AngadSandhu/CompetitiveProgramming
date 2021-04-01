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
map<int,int> trans;
map<int, int> last;
int nexta[100005];
int main(){
 	int n;
 	cin >> n;
 	vi v(n);
 	set<int>s;
 	for(int i = 0; i < n; i++) {cin >> v[i]; s.insert(v[i]);}
 	int uwu = 0;
 	for(auto e : s) {
 		trans[e] = uwu;
 		uwu++;
 	}
 	for(int i = 0; i < n; i++) v[i] = trans[v[i]];
 	memset(nexta, -1, sizeof(nexta));
 	for(int i = n - 1; i >= 0; i--) {
 		if(last.find(v[i]) != last.end()) {
 			nexta[i] = last[v[i]];
 		}
 		last[v[i]] = i;
 	}
 	int norep = n - 1;
 	ll total = 0;
 	for(int i = n - 1; i >= 0; i--) {
 		if(nexta[i] != -1) {
 			norep = min(norep, nexta[i] - 1);
 		}
 		total += (norep - i + 1);
 		
 	}
 	cout << total << "\n";
	return 0;
}