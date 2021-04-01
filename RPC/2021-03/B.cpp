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
int w[6] = {1, 5, 10, 20, 50, 100};
int a[6];
int main(){
	for(int i = 0; i < 6; i++) cin >> a[i];
	int total = 0;
	int p;
	for(int i = 0; i < 6; i++) {
		if(a[i] * w[i] >= total) {
			p = w[i];
			total = a[i] * w[i];
		}
	}
	cout << p << "\n";
	return 0;
}