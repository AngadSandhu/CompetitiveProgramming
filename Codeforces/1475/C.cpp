#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int a,b,k; cin >> a >> b  >> k;
        vector<int> d[2];
        vector<pair<int,int>> ed(k);
        d[0].resize(a);
        d[1].resize(b);
        for(int i = 0 ; i < k ; i++){
            int x; cin >> x;
            d[0][x-1]++;
            ed[i].first =x-1;
        }
        for(int i = 0 ; i < k ; i++){
            int x; cin >> x;
            d[1][x-1]++;
            ed[i].second=x-1;
        }
        ll ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans += k - d[0][ed[i].first] - d[1][ed[i].second] + 1;
        }
        cout << ans/2 << endl;
    }
	return 0;
}