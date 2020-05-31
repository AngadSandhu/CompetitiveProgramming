#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int main(){
	FIO;
	int t, caso = 0; cin >> t;
    while(t--){
        vector<int> v(3);
        for(int &i : v) cin >> i;
        sort(v.begin(),v.end());
        cout << "Case " << ++caso << ": " << v[1] << endl;
    }
	return 0;
}