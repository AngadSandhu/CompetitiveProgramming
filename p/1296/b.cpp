#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll res = 0;
        while(n >= 10){
            ll c = (ll)log10(n);
            res += (ll)pow(10,c);
            n = n -(ll)pow(10,c) + (ll)pow(10,c-1);
        }
        res += n;
        cout << res << endl;
    }
    return 0;
}