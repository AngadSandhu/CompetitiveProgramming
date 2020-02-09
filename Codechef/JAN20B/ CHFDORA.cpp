#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> ar;
int main() {
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ar.resize(n);
        for(int i = 0 ; i < n ; i++){
            ar[i].resize(m);
            for(int j = 0 ; j < m ; j++){
                cin >> ar[i][j];
            }
        }
        ll res = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int dir = 0 ; dir < n ; dir++){
                    if( (i-dir) < 0 || (i+dir) >= n || (j-dir) < 0 || (j+dir) >= m) break;
                    if((ar[i-dir][j]!=ar[i+dir][j]) || (ar[i][j-dir]!=ar[i][j+dir])) break;
                    res++;
                }
            }
        }
        cout << res << endl;
    }
	return 0;
}