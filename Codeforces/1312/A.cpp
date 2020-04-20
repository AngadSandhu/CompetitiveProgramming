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
        int n,m; cin >> n >> m;
        if(n%m == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}