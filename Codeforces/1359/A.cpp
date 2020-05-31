#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N

int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        if(m <= n/k) cout << m << endl;
        else cout << n/k-((m-(n/k) + (k-1)-1)/(k-1)) << endl;
    }
	return 0;
}