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
        ll x,y,l,r; cin >> x >> y >> l >> r;
        if(l > r) swap(l,r);
        ll res = -1, z = -1;
        for(ll i = l ; i <= r ; i++){
            if(res < ((x&i)*(y&i))){
                res = (x&i)*(y&i);
                z = i;
            }
        }
        cout << z << endl;
    }
	return 0;
}