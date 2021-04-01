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
 	int p;
 	cin >> p;
 	vii v;
 	for(int i = 0; i < p; i++) {
 		int c;
 		cin >> c;
 		for(int j = 0; j < c; j++) {
 			int x;
 			cin >> x;
 			v.pb(mp(x, i));
 		}
 	}
 	sort(all(v));
 	for(auto e: v) {
 		char cc = 'A' + e.second;
 		cout << cc;
 	}
 	cout << "\n";
	return 0;
}