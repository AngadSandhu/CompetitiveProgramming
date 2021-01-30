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
        ll n; cin >> n;
        if(__builtin_popcountll(n) == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
	return 0;
}