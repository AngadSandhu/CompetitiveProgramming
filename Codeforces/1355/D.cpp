#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
    ll n,s; cin >> n >> s;
    ll x = s - n+1;
    if(s < 2*n) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 0 ; i < n-1 ; i++) cout << "1 ";
        cout << x << endl;
        cout << n << endl;
    }
	return 0;
}